#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int n,m;
bool vis[N];
long long dma;
void dfs(long long sum,int idm){
	if(idm==m+1){
		if(dma<sum){
			dma=sum;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(sum==-1){
		    	dfs(a[i],idm+1);
			}else {
				dfs(sum&a[i],idm+1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(-1,1);
		cout<<dma;
	}else if(m==1){
		long long ma=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}else if(m==n){
		int ans;
		cin>>ans;
		for(int i=2;i<=n;i++){
			int a;cin>>a;
			ans=ans&a;
		}
		cout<<ans;
	}else if(m==2){
		long long ma=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ma=max(ma,a[i]&a[j]);
				}
			}
		}
		cout<<ma;
	}else{
		long long maa=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maa=max(maa,a[i]);
		}
		if(maa<4){
			int i1=0,i2=0,i3=0;
			for(int i=1;i<=n;i++){
				if(a[i]==3){
					i3++;
				}
				if(a[i]==2){
					i2++;
				}
				if(a[i]==1){
					i1++;
				}
			}
			if(i3>=m){
				cout<<"3";
			}else if(i2+i3>=m){
				cout<<"2";
			}else if(i1+i3>=m){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			int tn=n;int wei=0;
			bool f=1;
			while(n>=2){
				int ttn=tn>>1;
				if(ttn<<1!=tn){
					f=0;
					break;
				}
				wei++;
				tn=ttn;
			}if(f){
				if(m<=(n>>1)){
					cout<<(n>>1);
				}else{
					cout<<"0";
				}
			}else{
				dfs(-1,1);
				cout<<dma;
//				srand(time(0));
//				cout<<rand();
			}
		}
	}
	return 0;
}
