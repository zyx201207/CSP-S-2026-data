#include<bits/stdc++.h>
using namespace std;
/*
Basic method:
See a subway line as a node, and see the stations as edges.
1. calculate all line2line shortest time(Floyd O(N^3) is enough for 500)
2. For each query:
*  1. Find which lines they are on.
*  - Calculate terminalA(known)->lineB(M choices)->lineC(M choices)->terminalD(known) time.
*  2. Find the combination with the shortest time.
*  3. Add timePrep of both stations.
*/
int _TPNumber, cntLine, cntTerminal, maxCrossBy, cntQueries;
vector<int> timePrep;
vector<int> lineGTTerminalCnt;
/*
↓
Preparation: make_map. This data structure is used to record the time to go to each line in a station.
Unreachable station of this line will be filled with time INT_MAX(2147483647)
Data index declaration: terminal2LineTime[terminal][line] = time
*/
vector<vector<long long>> terminal2LineTime;
/*
... This means, if you want to switch from line a to line b at terminal c, you'll need to walk for time...
$ terminal2LineTime[c][a] + terminal2LineTime[c][b] $
So we can define...
*/
vector<vector<long long>> line2LineTime;
/*
...as this, to simplify the expression.
Data index daclaration: $ line2LineTime[a][b] = min { terminal2LineTime[c_i][a] + terminal2LineTime[c_i][b] } $
Note: $ c_i $ is the set of all stations. If line a can't goto line b directly, in $Stage 1 & 2-1$ it will be INT_MAX
*/
int main(){
	// Stage 0-1: Initialize I/O streams
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	// Stage 0-2: I/O streams untie & un-sync to increase R/W speed.
	// Because the #7 testpoint has a 13,632KB input file... Which is 13.63MB!
	cin.tie(0);
	cout.tie(0);
	std::ios::sync_with_stdio(false);
	// Stage 1-1: Input metadata
	cin>>_TPNumber>>cntLine>>cntTerminal>>maxCrossBy>>cntQueries;
	// Stage 1-2: Resize vectors
	lineGTTerminalCnt.resize(cntLine+2);
	timePrep.resize(cntTerminal+2);
	terminal2LineTime.resize(cntTerminal+2);
	line2LineTime.resize(cntLine+2);
	// Stage 1-3-1: Prepare "terminal to line" map data
	for(int i=1;i<=cntTerminal;i++){
		terminal2LineTime[i].resize(cntLine+2);
		for(int j=1;j<=cntLine;j++){
			if(i!=j) terminal2LineTime[i][j] = LLONG_MAX / 2048; // Fill as TIME-MAX(prep:unreachable)
			else terminal2LineTime[i][j] = 0;
		}
	}
	//Stage 1-3-2: Prepare "line to line" map data
	for(int i=1;i<=cntLine;i++){
		line2LineTime[i].resize(cntLine+2);
		for(int j=1;j<=cntLine;j++){
			if(i!=j) line2LineTime[i][j] = LLONG_MAX / 2048;
			else line2LineTime[i][j] = 0;
		}
	}
	// Stage 1-4: Input per-station preparation time
	for(int i=1;i<=cntTerminal;i++){
		int curPTime;
		cin>>curPTime;
		timePrep[i]=curPTime;
	}
	// Stage 1-5: Input t2l time data & process them
	// Time exp: Same as input: O(N*ΣK_i)
	for(int curLine=1;curLine<=cntLine;curLine++){
		int LGGTcnt;
		cin>>LGGTcnt;
		lineGTTerminalCnt[curLine]=LGGTcnt;
		for(int j=1;j<=LGGTcnt;j++){
			int curCrossTerminal, walkThroughtTime;
			cin>>curCrossTerminal>>walkThroughtTime;
			terminal2LineTime[curCrossTerminal][curLine] = walkThroughtTime;
		}
	}
	// Stage summary: Time exp: O()
	// Stage 2-1: Initialize l2l time data
	// Time exp: O(M*N^2)
	for(int i=1;i<=cntTerminal;i++){
		for(int j=1;j<=cntLine;j++){
			for(int k=1;k<=cntLine;k++){
				line2LineTime[j][k] = min(line2LineTime[j][k], terminal2LineTime[i][j] + terminal2LineTime[i][k]); // LLONG, max 2147483647 * 2 not exceeded :)
				line2LineTime[k][j] = line2LineTime[j][k];
			}
		}
	}
	// Now, l2l time data is the min value to travel from [j]->[k] directly.
	// Stage 2-2: Floyd calculation.
	// Time exp: O(N^3)
	for(int i=1;i<=cntLine;i++){
		for(int j=1;j<=cntLine;j++){
			for(int k=1;k<=cntLine;k++){
				line2LineTime[i][j] = min(line2LineTime[i][j], line2LineTime[i][k] + line2LineTime[j][k]);
			}
		}
	}
	// Now, l2l min time data is fully calculated.
	// Stage summary: Time exp O((M+N)*N^2)
	// Stage 3: Answer each query.
	// Time exp: O(Q*N^2)
	for(int curQuery=1;curQuery<=cntQueries;curQuery++){
		// [Q] Stage 3-1: Input query metadata
		// Time exp: O(1)
		int QsourceTerminal, QtargetTerminal;
		cin>>QsourceTerminal>>QtargetTerminal;
		// [Q] Stage 3-2: Calculate total prepare time
		// Time exp: O(1)
		int QterminalPrepTime = timePrep[QsourceTerminal]+timePrep[QtargetTerminal];
		// [Q] Stage 3-3: Calculate min T2T time
		// Time exp: O(N^2)
		long long Qterminal2TerminalTime = LLONG_MAX;
		for(int i=1;i<=cntLine;i++){
			for(int j=1;j<=cntLine;j++){
				long long curTerminal2TerminalTime = terminal2LineTime[QsourceTerminal][i]+line2LineTime[i][j]+terminal2LineTime[QtargetTerminal][j];
				Qterminal2TerminalTime = min(Qterminal2TerminalTime,curTerminal2TerminalTime);
			}
		}
		// [Q] Stage 3-4: Calculate final TRAVEL time & output.
		// Time exp: O(1)
		int QtravelTime = QterminalPrepTime + Qterminal2TerminalTime;
		cout<< QtravelTime<<endl;
	}
}