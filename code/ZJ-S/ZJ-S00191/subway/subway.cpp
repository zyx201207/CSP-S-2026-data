#include<bits/stdc++.h>
#define int long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
const int N=5e2+5,M=5e5+5,Q=1e5+5;
int c,n,m,d,q,w[M],k[N],fl[N][N],nwj,nwo,nwp,nwq,nwt,ans[Q],fs[Q],l,r,tg[Q],gwt[Q];
//          fastest_lu between the lines   fs_tothestop     target of this round
struct sw{//subway
	int a,t;
}nw;
struct qu{//question,not"qu"OvO
	int x,y,i;
}qs[Q];
vector<sw>ls[N];
//the stop on the lines
vector<int>s_l[M],s_i[M];
//stop(what lines stop here),(what is the i(dijige) of this stop in ls)
bool by_x(qu a,qu b){
	return (a.x==b.x)?(a.y==b.y)?a.i>b.i:a.y<b.y:a.x<b.x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];	
	memset(fl,0x3f,sizeof(fl));
	memset(fs,0x3f,sizeof(fs));
	for(int i=1;i<=n;i++){
		fl[i][i]=0;//shunshou
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>nw.a>>nw.t;
			ls[i].push_back(nw);
			s_l[nw.a].push_back(i);
			s_i[nw.a].push_back(j);
		}
	}
	//first:one_stop to change the lines
	for(int i=1;i<=m;i++){//stop
		for(int j=0;j<s_i[i].size();j++){//starting line
			for(int o=j+1;o<s_i[i].size();o++){//ijklmn are used QAQ,finishing line
				nwj=s_l[i][j];nwo=s_l[i][o];
				fl[nwj][nwo]=fl[nwo][nwj]=min(fl[nwj][nwo],ls[nwj][s_i[i][j]].t+ls[nwo][s_i[i][o]].t);
			}
		}
	}
	//oh it's n^2m,unable to ac qaq
	//really?
	//it can't be on^2m,can't make it.
	//it's max is onm!
	//if i ac this maybe i can got s-1
	//still 2h40min,youshizaiwo!
//	for(int i=1;i<=n;i++){//starting line
//		for(int j=1;j<=n;j++){//finishing line
//			cout<<fl[i][j]<<' ';
//		}
//		cout<<'\n';
//	}tested 1,2. no problem.
	//second:fastest_lu between the lines
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int o=1;o<=n;o++){
				fl[j][o]=min(fl[j][o],fl[j][i]+fl[i][o]);
			}
		}
	}
//	cerr<<fl[112][57]<<'\n'<<fl[38][102]<<'\n'<<fl[55][10]<<'\n';
//	cerr<<fl[14][8];
//	for(int i=1;i<=n;i++){//starting line
//		for(int j=1;j<=n;j++){//finishing line
//			cout<<fl[i][j]<<' ';
//		}
//		cout<<'\n';
//	}tested 1,2. no problem.
	//lst:fastest_lu between the stop
	//for every stop,find two lines
	//but it's n^4
	//can i find better solution?
	//well i'm toooooooo nerverous to think
	//still i find it
	//find a line, find another line,and find the stop on the ather line
	//so it's not last,just third!
//	for(int i=1;i<=n;i++){//nw line
//		for(int j=1;j<=n;j++){//at line
//			for(int o=0;o<k[j];o++){//stop of at line
//				fls[i][ls[j][o].a]=min(fls[i][ls[j][o].a]+ls[j][o].t,fl[i][j]);
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<fls[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	//lst:fastest_lu between the stop!yes!made it!
	//all in n^3!
	//good chutiren!
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int o=0;o<k[i];o++){
//				fs[ls[i][o].a][j]=min(fls[ls[i][o].a][j]+ls[i][o].t,fls[i][j]);
//			}
//		}
//	}
	//now answer!
	//another problem.limit of memory.
	//try plan B.
	//we must solve the dis between stop and lines.
	//but it's qn^2.
	//no way to go?
	//i believe there will be a way.
	//chedaoshanqianbiyoulu.
	//lixiandafa!
	for(int i=1;i<=q;i++){
		cin>>qs[i].x>>qs[i].y,qs[i].i=i;
//		if(qs[i].x>qs[i].y)swap(qs[i].x,qs[i].y);
	}
//	sort(qs+1,qs+q+1,by_x);
//	for(int i=1;i<=q;i++){
//		if(qs[i].x==qs[i-1].x&&qs[i].y==qs[i-1].y)gwt[qs[i].i]=gwt[qs[i-1].i],qs[i].i=qs[i-1].i,ans[qs[i].i]-=w[qs[i].x]+w[qs[i].y];
//		else gwt[qs[i].i]=qs[i].i;
//	}
	for(int i=1;i<=q;i++){
		l=i;
		nwq=qs[i].x;
//		while(qs[i].x==nwq)i++;
//		i--;
		r=i;
//		cerr<<"x:"<<qs[i].x<<"\n";
		for(int j=l;j<=r;j++)tg[qs[j].y]=qs[j].i;
		for(int j=0;j<s_l[qs[i].x].size();j++){//the i of st line
//			cerr<<"jstart"<<j<<"\n";
			nwj=s_l[qs[i].x][j];//st_line
			nwt=ls[nwj][s_i[qs[i].x][j]].t;
//			cerr<<"j:"<<j<<"st line:"<<nwj<<"in cost:"<<nwt<<"\n";
			for(int o=1;o<=n;o++){//finish line
//				cerr<<"o:"<<o<<"\n";
				for(int u=0;u<ls[o].size();u++){//the i of fi stop
					nwp=ls[o][u].a;//the pos of finish stop
//					cerr<<"the pos of finish stop:"<<nwp<<"\n";
//					cerr<<"one time\n";
//					if(tg[s_i[o][nwp]])cerr<<"one time\n";
					if(tg[nwp])fs[tg[nwp]]=min(fs[tg[nwp]],nwt+fl[nwj][o]+ls[o][u].t);
//					cerr<<"one time\n";
				}
//				cerr<<"over u\n";
			}
//			cerr<<"over o\n";
		}
//		cerr<<"over\n";
		for(int j=l;j<=r;j++)tg[qs[j].y]=0,ans[qs[j].i]=fs[qs[j].i];
	}
	for(int i=1;i<=q;i++)ans[qs[i].i]+=w[qs[i].x]+w[qs[i].y];
//	for(int i=1;i<=q;i++){
//		if(qs[i].x==qs[i-1].x&&qs[i].y==qs[i-1].y)ans[qs[i].i]=ans[qs[i].i-1];
//	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	//well,when i'm writing this,my head is singning"menggaixingla"
	//time:(nm+qlogq) i think
	//zhengming:for every dian,we max find one time
	//and the dian_sum max is m.
	//only 3 bug left!but i only have 1 hour left too
	//i can't solve it,so it turns to baoli again.
	//ai,wojinglila
	//tingtianyoumingba
	//give me 40pts plz......
	return 0;
}
//debuging. i'm toooooooo nerverous.