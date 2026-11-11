#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
const int N=2e5+5;
using namespace std;
ll n,num[N],tmpnum,ans;
char c[N],tmp;
bool flag;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cin>>c[i];
	}
	while(l<r){
		if(tmpnum==0){
			if(num[l]>num[r]){
				tmpnum=num[l]-num[r];
				tmp=c[l];
				flag=0;
				if(c[l]!=c[r]) ans+=num[r];
				r--;
			}else{
				tmpnum=num[r]-num[l];
				tmp=c[r];
				flag=1;
				if(c[l]!=c[r]) ans+=num[l];
				if(num[l]==num[r]) r--;
				l++;
			}
		}else{
			if(flag){
				if(num[l]>tmpnum){
					if(c[l]!=tmp) ans+=tmpnum;
					flag=0;
					tmpnum=num[l]-tmpnum;
					tmp=c[l];
					r--;
				}else{
					if(c[l]!=tmp) ans+=num[l];
					flag=1;
					tmpnum=tmpnum-num[l];
					l++;
					if(tmpnum==0) r--;
				}
			}else{
				if(num[r]>tmpnum){
					if(c[r]!=tmp) ans+=tmpnum;
					flag=1;
					tmpnum=num[r]-tmpnum;
					tmp=c[r];
					l++;
				}else{
					if(c[r]!=tmp) ans+=num[r];
					flag=0;
					tmpnum=tmpnum-num[r];
					r--;
					if(tmpnum==0) l++;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
