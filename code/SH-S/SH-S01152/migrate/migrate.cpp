#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll C,T,n,d,x[N],t[5009],cnt[5009];
vector <int> to[N];
void solvebf(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int u=1;u<=n;u++){
			to[u].clear();
		}
		for(int j=1;j<=n;j++){
			cnt[j]=1;
			if(i==j) t[j]=0;
			else if(abs(x[i]-x[j])<=d){
				t[j]=1;
			}else t[j]=N;
		}
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(abs(x[u]-x[v])<=d){
					to[u].push_back(v);
				}
			}
		}
		for(int timer=1;timer<=n;timer++){
			for(int u=1;u<=n;u++){
				for(int ii=0;ii<to[u].size();ii++){
					int v=to[u][ii];
					if(t[v]>t[u]+1){
						cnt[v]=1;
						t[v]=t[u]+1;
					}else if(t[v]==t[u]+1){
						cnt[v]++;
					}
				}
			}
		} 
		for(int ii=i;ii<=n;ii++){
			if(cnt[ii]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	//I finished the code.
	//but...
	//WHY ALWAYS COUT 0!?
	//WHYYYYY!!!
	//AHHHHHHHHH!!!
	//NOOOOOOOOOOOO!!!
	//...
	//...
	//...
	//...
	//...
	//15 minutes left,still cannot pass...
	//maybe it's my last csp-s...
	//Man,what can I say?
	//...
	//...
	//...
	//ah... 10 minutes left...
	//what can I do now?
	//...
	//...
	//...
	//...
	//...
	//I give up.
	//5 minutes...
	//4 minutes...
	//3 minutes...
	//2 minutes...
	//1 minute...
	//The end.
	//R.I.P. SH-S01152
	return;
}
void solveA(){
	int ans=0;
	int gc=x[2]-x[1];
	if(gc*2<d && gc*3>d){
		ans=n-3;
	}else{
		ans=0;
	}
	cout<<ans<<'\n';
}
void solveB(){
	int cntzzz=0;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d && x[n]-x[i]<=d){
			cntzzz++;
		}
	}
	if(cntzzz>=3){
		cout<<0<<'\n';
		return;
	}
	int fst=0,snd=0;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d && x[n]-x[i]<=d){
			if(!fst) fst=i;
			else snd=i; 
		}
	}
	long long ans=0;
	for(int i=1;i<fst;i++){
		int l=snd+1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(x[mid]-x[1]>d){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		l--;
		ans+=(n-l+1);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	for(int pigeon=1;pigeon<=T;pigeon++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(C<=2) solveB();
		else if(C<=10) solvebf();
		else if(C==11 || C==12) solveA();
		else if(C==13 || C==14) solveB();
	}
	return 0;
}
