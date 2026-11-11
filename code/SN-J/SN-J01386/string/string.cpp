#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,ans,cnt,nxt; 
string s;
struct st{
	char c;
	int b;
}a[20005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c;
		ans+=a[i].b;
	}
	cnt=n;
	for(int i=1;i<=n;i++){
		//cout<<sum<<" "<<i;
		if(abs(i-cnt)<=1){
			if(a[i].c!=a[cnt].c){
				sum+=(a[i].b+a[cnt].b)/2;
			}
			break;
		} 
		int now=0;
		if(a[i].b>=a[cnt].b){
			now=abs(a[i].b-a[cnt].b);
			if(a[i].c!=a[cnt].c){
				sum+=now;
			}
			if(a[i].b!=a[cnt].b){
				a[i].b-=a[cnt].b;
				i--;
			}else if(a[i].b==a[cnt].b){
				sum+=a[i].b;
			} 
			cnt--;
		}else if(a[i].b<a[cnt].b&&a[i].c!=a[cnt].c){
			now=abs(a[i].b-a[cnt].b);
			if(a[i].c!=a[cnt].c){
				sum+=now;
			}
			a[i].b-=a[cnt].b;
		}	
	}
	cnt=0;
	for(int i=n;i>0;i--){
		if(abs(i-cnt)<=1){
			if(a[i].c!=a[cnt].c){
				nxt+=(a[i].b+a[cnt].b)/2;
			}
			break;
		} 
		int now=0;
		if(a[i].b>=a[cnt].b){
			now=abs(a[i].b-a[cnt].b);
			if(a[i].c!=a[cnt].c){
				nxt+=now;
			}
			if(a[i].b!=a[cnt].b){
				a[i].b-=a[cnt].b;
				i++;
			}else if(a[i].b==a[cnt].b){
				nxt+=a[i].b;
			} 
			cnt++;
		}else if(a[i].b<a[cnt].b&&a[i].c!=a[cnt].c){
			now=abs(a[i].b-a[cnt].b);
			if(a[i].c!=a[cnt].c){
				nxt+=now;
			}
			a[i].b-=a[cnt].b;
		}
	}
	cout<<min(sum,nxt);
} 
