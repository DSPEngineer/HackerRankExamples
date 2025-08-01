<center><B><U>Optiver – Hacker Rank  31 July 2025</U></B></center>

__*Question 1*__

A satellite network is experimenting with a distributed communication protocol based on satellite connections.
During System tests, the team wants to ensure that messages they sent are processed in the correct order. The protocol look like so:

1. Message is sent from earth directly yo one or more satellites.

2. Every satellite that receives the message forwards it to its direct connections, in increasing order of SatelliteId, as long as they haven’t received it yet.
 
3. Once all its direct connections have received the message, a satellite processes the message and reports back to Earth.


__*Problem Statement*__

You will receive the stream of N instructions. Each instruction can be one of the following actions:

 - SatelliteConnected – indicates that a satellite is connected to the network.
   - Parameters:  SatelliteId.

 - RelationshipEstablished - indicates a (tow-way) relationship between satellites.
   - Parameters:  SatelliteId1, SatelliteId2 .
 - MessageReceived - indicates that  a set of M satellites received a message.
   - Parameters:  M, SatelliteId1, SatelliteId2, … SatelliteIdM


__*Important Notes*__

 - It takes 10 seconds for a satellite to forward a message to one of its connections. This procedure is synchronous and atomic, i.e. for every sender, only one message can be forwarded at a time and it takes exactly 10s for it to complete.

 - As soon as the forwarding procedure is complete, you may assume that the entire network knows that the receiver satellite has been notified, i.e. no further attempts to notify it must be performed.

 - While the forwarding procedure is not complete, any other satellite may attempt to forward messages to the same connection. In this case, the same 10 seconds are spent by sender.

 - A satellite will never try to notify the satellite that notified it.

 - It takes a satellite 30 seconds to process the message and report back to Earth.

 - If two satellites report back to Earth at the same time, the one with smaller SatelliteId arrives first. 

__*Function Description*__

Complete the functions SatelliteConnected, RelationshipEstablished and MessageReceived of the SatelliteNetwork class, which correspond to the instructions described above.

Consider the below functions available to you which must be called in the correct order:

- OnSatelliteReportedBack: should be called to notify that a satellite reported back to Earth, in order.
  - Parameters: SatelliteId.

- ErrDuplicateSatellite: should be called if a satellite connects more than once.
  - Parameters: SatelliteId.

- ErrInvalidSatellite: should be called if a referenced SatelliteId does not exist. The whole instruction referring to this satellite must be skipped.
  - Parameters: SatelliteId.

__*Constraints*__

  - 0 ≤ SatelliteId < 216
  - 0 ≤ N < 232
  - 0 ≤ M < 232


__*Input Format For Custom Testing*__

Input to the program is specified using a simple text format. The format and details of parsing are not relevant to answering the question but custom input can be used to help with development and debugging.

The first line of input contains an integer N that denotes the number of instructions.
Each of the N subsequent lines contains one of the instructions as in the format below: 

- SatelliteConnected < SatelliteId >
- RelationshipEstablished < SatelliteId1 > < SatelliteId2 >
- MessageReceived < M > < SatelliteId1 > < SatelliteId2 > ... < SatelliteIdM >


Some example inputs and their expected outputs are described below.

__*Sample Case 0*__

Sample input for custom testing:
```
 5
 SatelliteConnected 1
 SatelliteConnected 2
 SatelliteConnected 3 
 RelationshipEstablished 2 1
 MessageReceived 1 2
 ```

Expected output:
```
 SatelliteReportedBack: 1  
 SatelliteReportedBack: 2
```

Explanation:

There are 3 satellites (1, 2 and 3) and there is one relationship between satellite 2 and satellite 1. Only satellite 2 directly receives the message from Earth.

Satellite 2 takes 10s to notify satellite 1, then 30s more to process the message and report back to Earth, totalling 40s.

Satellite 1 doesn't need to forward the message to anyone, so it only takes 30s to process the message and report back to Earth. Since it received the message at t=10s, their report arrives on Earth at t=40s.

Satellite 1 ultimately arrives on Earth first because its SatelliteId is smaller.


__*Sample Case 1*__

Sample input for custom testing:
```
 12
 SatelliteConnected 1
 SatelliteConnected 2
 SatelliteConnected 3
 SatelliteConnected 4
 SatelliteConnected 5
 RelationshipEstablished 1 3
 RelationshipEstablished 1 2
 RelationshipEstablished 2 5
 RelationshipEstablished 3 2
 RelationshipEstablished 3 4
 RelationshipEstablished 3 5
 MessageReceived 2 1 3
```

Expected output:
```
 SatelliteReportedBack: 1  
 SatelliteReportedBack: 2
 SatelliteReportedBack: 3
 SatelliteReportedBack: 4
 SatelliteReportedBack: 5
```

Explanation:

The message is sent to satellites 1 and 3, and because of this they don't try to notify each other (despite having a relationship).

Satellite 1 takes 10s to notify satellite 2, then 30s to process the message and report back to Earth, totalling 40s.

Satellite 2 takes 10s to notify satellite 5 (from t=10s), then 30s to process the message and report back to Earth on t=50s.

Satellite 3 notifies satellite 2 on t=10s (simultaneously with satellite 1), then satellite 4 on t=20s. Satellite 5 is next, but it has just been notified on t=20s by satellite 2, so it is skipped. Satellite 3 then takes 30s more to process the message and report back to Earth, totalling 50s since being notified on t=0.

Satellite 4 is notified on t=20s by satellite 3, then process the message and report back to Earth on t=50s.

Satellite 5 is notified on t=20s by satellite 2, then process the message and report back to Earth on t=50s.

Since satellites 2, 3, 4 and 5 are all notified at the same time, on t=50s, they're reported in increasing order of ids.
