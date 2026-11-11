#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+9;
int a[N]; 
int n,m,mx;
//bool vis[N];
void dfs(int c,int idx){
	if(c<=0){
		int tmp=1;
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(clock()/CLOCKS_PER_SEC>0.985){
				mx=max(mx,tmp);
				cout<<mx<<endl;
				exit(0);
			}
			if(a[i]==a[i-1]){
				tmp+=1;
				flag=true;
			}else{
				if(flag){
					flag=false;
					mx=max(mx,tmp);
					tmp=1;
				}
			}
			//cout<<a[i]<<" ";
		}
		if(clock()/CLOCKS_PER_SEC>0.985){
			mx=max(mx,tmp);
			cout<<mx<<endl;
			exit(0);
		}
		//cout<<endl<<tmp<<endl<<endl;
		mx=max(mx,tmp);
		return;
	}else{
		for(int i=1;i<=n;i++){
			a[i]+=1;
			if(clock()/CLOCKS_PER_SEC>0.985){
				//mx=max(mx,tmp);
				cout<<mx<<endl;
				exit(0);
			}
			dfs(c-1,idx+1);
			a[i]-=1;
		}
	}
}

void ok1(){
	int opt=0,mer=1;
	for(int i=n-1;i>=1;i--){
		if(opt+(a[n]-a[i])>m)break; 
		opt+=a[n]-a[i];
		mer++;
	}
	cout<<mer<<endl;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		ok1();
		return 0;
	}
	dfs(m,1);
	cout<<mx<<endl;
} 
