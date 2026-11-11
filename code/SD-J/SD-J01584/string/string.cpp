#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 2e5+7;
using namespace std;
int n;
ll gl[maxn],gr[maxn];
char gc[maxn],C;
ll pos=1,sum,ans,L,R,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		char s;
		cin>>a>>s;
		gc[i]=s,gl[i]=pos,gr[i]=pos+a-1;
		pos=pos+a;
	}
	pos--;
	cnt=(pos+1)/2+1; 
	for(int i=1;i<=n;i++){
		if(cnt>=gl[i]&&cnt<=gr[i]){
			L=cnt,R=gr[i],C=gc[i],sum=i; 
			break;
		}
	}
	while(1){
		ll lL=pos-R+1,rR=pos-L+1;
		ll x=upper_bound(gl+1,gl+n+1,lL)-gl-1;//l
		if(gr[x]>=rR){
			ans+=(gc[x]==C)?0:rR-lL+1;
		}
		else{
			while(gr[x]<rR){
				ans+=(gc[x]==C)?0 :(gr[x]-lL+1); 
				lL=gr[x]+1;
				x++; 
			}
			if(gr[x]>=rR){
				ans+=(gc[x]==C)?0:rR-gl[x]+1;
			}
		} 
		if(R==pos) break;
		sum++; 
		L=gl[sum],R=gr[sum],C=gc[sum]; 
	}
	cout<<ans<<'\n';
	return 0; 
}/*
3 
2 a 
2 b 
1 c
6
1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
*/
