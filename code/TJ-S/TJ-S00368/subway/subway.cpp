#include<bits/stdc++.h>
using namespace std;

struct sub {
	int id;
	int time1;
	vector<int> time2;

	vector<bool> toW;

	int wayN;
	bool only;
};

int number;
int wayN,subN,maxTWay;
int queN;

sub subs[500005];

bool ways[505][505];
int w_t_min[505][505];

int go(int now,int time,int haveCount,bool have[]) {

	have[now]=true;
	if(haveCount==wayN) {
		return time;
	}

	for(int n=0; n<wayN; n++) {
		if(have[n]) {
			haveCount++;
		}
	}

	for(int n=0; n<wayN; n++) {
		if(have[n]) {
			continue;
		}
		time+=subs[now].time2[n];


		if(w_t_min[now][n]!=0) {
			time=w_t_min[now][n];
			continue;
		}
		int t=go(n,time,haveCount,have);

		if(t<time) {
			time=t;
		}

		w_t_min[now][n]=t;

		have[n]=true;
	}

	return time;
}

int main() {
	ifstream in;
	in.open("subway.in");
	ofstream out;
	out.open("subway.out");

	in>>number>>wayN>>subN>>maxTWay>>queN;

	for(int i=0; i<subN; i++) {
		subs[i].id=i;
		in>>subs[i].time1;
	}
	for(int i=0; i<wayN; i++) {
		int sub_now_n;
		in>>sub_now_n;
		for(int j=0; j<sub_now_n; j++) {
			int sub_n=0;
			in>>sub_n;
			in>>subs[sub_n].time2[i];

			subs[sub_n].toW[i]=true;
			subs[sub_n].wayN++;

			if(subs[sub_n].wayN>1) {
				subs[sub_n].only=false;
			} else {
				subs[sub_n].only=true;
			}
		}

	}

	for(int w=0; w<wayN; w++) {
		for(int n=0; n<subN; n++) {
			if(subs[n].only) {
				continue;
			}
			for(int w2=0; w<wayN; w2++) {
				if(subs[n].toW[w2]) {
					ways[w][w2]=true;
				}
			}

		}
	}

	for(int q=0; q<queN; q++) {
		int sin=0,sout=0;
		bool only=false;
		int toWay=0;
		bool haveWay[505];
		int time=0;

		int nowSub=sin;

		in>>sin>>sout;

		for(int n=0; n<wayN; n++) {
			if(subs[sin].toW[n]==subs[sout].toW[n]) {
				only=true;
			} else {
				toWay=subs[sout].toW[n];
			}
		}

		for(int n=0; n<wayN; n++) {
			haveWay[n]=true;
			time+=subs[nowSub].time1;

			int t=0;

			if(subs[sin].toW[n]) {
				t=go(n,time,1,haveWay);
			}

			if(t<time) {
				time=t;
			}
		}

		time+=subs[sout].time1;

		out<<time;

	}

	in.close();
	out.close();

	return 0;
}
 
