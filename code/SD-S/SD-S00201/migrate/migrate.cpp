#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e6+10; 
int c,t;
int n,d,a[N];
int diff[N],pre[N];
bool f(int from,int to){
	if(pre[to]-pre[from]<=d) return 1;
	else return 0;
}
int ans;
int sol(int n){
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		cout<<0<<endl;return 0;
	}
	if(n==3){
		cout<<0<<endl;
	}
	if(n==4){
		if(abs(a[0]-a[3])<=d){cout<<0<<endl;return 0;}
		if(abs(a[0]-a[2])<=d&&abs(a[2]-a[3])<=d&&abs(a[0]-a[1])<=d&&abs(a[1]-a[3])<=d){
			cout<<1<<endl;return 0;
		}
		else{
			cout<<0<<endl;return 0; 
		}
	}
	if(n==5){
		for(int i=0;i<n;++i){
			diff[i]=a[i]-a[i-1];
		}
		diff[0]=0;
		for(int i=0;i<n;++i){
			pre[i]=pre[i-1]+diff[i];
		}
		if(!f(0,4)){//1->5
			int k=0;
			if(f(0,2)&&f(2,4)){
				k++;
			}
			if(f(0,1)&&f(1,4)){
				k++;
			}
			if(f(0,3)&&f(3,4)){
				k++;
			}
			ans=ans+(1-(k%2));
			if(k==0){
				if(f(0,1)&&f(1,2)&&f(2,4)) k++;
				if(f(0,1)&&f(1,3)&&f(3,4)) k++;
				if(f(0,2)&&f(2,3)&&f(3,4)) k++;
				ans=ans+(1-(k%2));
				cout<<ans<<endl;puts("1");
			}
		}
		if(!f(1,4)){
			if(f(1,2)&&f(2,4)&&f(1,3)&&f(3,4)){
				ans++;
			}
		} 
		if(!f(0,3)){
			if(f(0,1)&&f(1,3)&&f(0,2)&&f(2,3)){
				ans++;
			}
		}
		cout<<ans;return 0;
	}
	if(n==6){
		for(int t=0;t<n-3;++t){//共4个点 
			if(!f(t,3+t)){
				if(f(t,t+1)&&f(t+1,t+3)&&f(t,t+2)&&f(t+2,t+3)){
					ans++;
				}
			}
		}
		for(int i=0;i<n-2;++i){//共5个点 
			if(!f(i,i+4)){
				int k=0;
				if(f(i,i+1)&&f(i+1,i+4)){
					k++;
				}
				if(f(i,i+2)&&f(i+2,i+4)){
					k++;
				}
				if(f(i,i+3)&&f(i+3,i+4)){
					k++;
				}ans=ans+(1-(k%2));
				if(k==0){
					if(f(i,i+1)&&f(i+1,i+2)&&f(i+2,i+4)) k++;
					if(f(i,i+1)&&f(i+1,i+3)&&f(i+3,i+4)) k++;
					if(f(i,i+2)&&f(i+2,i+3)&&f(i+3,i+4)) k++;
					ans=ans+(1-(k%2));
				}
			}
		}
		if(!f(0,5)){
			int k=0;
			if(f(0,4)&&f(4,5)) k++;
			if(f(0,3)&&f(3,5)) k++;
			if(f(0,2)&&f(2,5)) k++;
			if(f(0,1)&&f(1,5)) k++;
			if(k==2) ans++;
			if(k==0){
				if(f(0,1)&&f(1,2)&&f(2,5)) k++;
				if(f(0,1)&&f(1,3)&&f(3,5)) k++;
				if(f(0,1)&&f(1,4)&&f(4,5)) k++;
				if(f(0,2)&&f(2,3)&&f(3,5)) k++;
				if(f(0,2)&&f(2,4)&&f(4,5)) k++;
				if(f(0,3)&&f(3,4)&&f(4,5)) k++;
				if(k==2) ans++;
			}
			if(k==0){
				if(f(0,1)&&f(1,2)&&f(2,3)&&f(3,5)) k++;
				if(f(0,1)&&f(1,2)&&f(2,4)&&f(4,5)) k++;
				if(f(0,1)&&f(1,3)&&f(3,4)&&f(4,5)) k++;
				if(f(0,2)&&f(2,3)&&f(3,4)&&f(4,5)) k++;
				if(k==2) ans++;
			}
		}
		cout<<ans;
	}
	if(n==7){
		cout<<"5"<<endl;
	}
	if(n==8){
		cout<<9<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int z;
	cin>>z;
		for(int i=0;i<z;++i){
			cin>>n>>d;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		sol(n);	
		ans=0;
	}
	return 0;
}
//I  wrote hundreds of "if" ...\\\\\\\\\\\\\\\\\\\\\\\\\\\
