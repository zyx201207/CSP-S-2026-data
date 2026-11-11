#include<bits/stdc++.h>
using namespace std;

#define ll long long 
const int N=2e5+20;

ll le[N];

int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ll n,len,k=0;
	cin>>n;
	string a=" ";
	char y1,y2;
	cin>>len>>y1;
	le[1]=len;
	a+=y1;
	ll las=1;
	for(int i=2;i<=n;i++){
		cin>>k>>y2;
		if(y2==y1){
			le[las]+=k;
		}
		else{
			las++;
			le[las]+=k;
			a+=y2;
			y1=y2;
		}
		len+=k;
	}
	/*
	for(int i=1;i<=las;i++){
		cout<<le[i]<<":"<<a[i]<<endl;
		
	}
	cout<<len;
	*/
	ll middle = (len)/2;
	//si=sl+1-i
	ll ans=0;
	ll l=1,r=las,kk=0;
	while(kk<middle){
		if(a[l]!=a[r]){
			if(le[l]>le[r]){
				ans+=le[r];
				kk+=le[r];
				le[l]-=le[r];
				le[r]=0;
				
				r--;
				
				
			}
			else{
				ans+=le[l];
				kk+=le[l];
				
				le[r]-=le[l];
				le[l]=0;
				l++;
				
			}
			if(le[r]==0) r--;
		}
		else {
			if(le[l]>le[r]){
				kk+=le[r];
				
				le[l]-=le[r];
				le[r]=0;
				r--;
				
			}
			else{
				kk+=le[l];
				
				le[r]-=le[l];
				le[l]=0;
				l++;
				
			}
			if(le[r]==0) r--;
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
