#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],t[50],ans,v[200005];
void hs(int x){
	for(int i=0;;i++){
		if(x<=0)break;
		t[i]+=x%2;
		x/=2;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		hs(a[i]);
		v[i]++;
	}
	for(int j=1;;j++){
		int w=100,cnt=0,z;
		for(int i=35;i>=0;i--){
			if(t[i]>=m){
				cnt++;
				if(cnt==j){
					w=i;
					break;
				}
			}
		}
		if(w==100)break;
		memset(t,0,sizeof(t));
		z=pow(2,w),ans+=z;
		for(int i=1;i<=n;i++){
			if((a[i]&z)==z&&v[i]==j){
				hs(a[i]);
				v[i]++;
			}
		}
	}
	cout<<ans;
	return 0;
}
//9:12    finish
//9:52    there is a bug ! find where is it
//10:24   finally find it and debug quickly! hahahahaha
