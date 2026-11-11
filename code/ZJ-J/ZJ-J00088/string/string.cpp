#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
char sl1[MAXN],sl2[MAXN];
string s;
long long n,a1[MAXN],a2[MAXN],ans,sums,mnsum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a1[i]>>sl1[i];
    	sums+=a1[i];
	}
    for(int i=1;i<=n;i++){
    	a2[i]=a1[n-i+1];
    	sl2[i]=sl1[n-i+1];
	}
	int q1,q2;                   
	q1=a1[1],q2=a2[1];
	for(int i1=1,i2=1;i1<=n,i2<=n;){
		long long minn=min(q1,q2);
		mnsum+=minn;
		if(mnsum>=sums/2){
			if(sl1[i1]!=sl2[i2]) ans=ans+(minn-(mnsum-sums/2));
			break;
		}
		if(sl1[i1]!=sl2[i2]) ans+=minn;
		if(q1>q2){
			i2++;
			q1=q1-q2;
			q2=a2[i2];
			continue;
		}
		if(q2>q1){
			i1++;
			q2=q2-q1;
			q1=a1[i1];
			continue;
		}
		if(q1==q2){
			i1++,i2++;
			q1=a1[i1],q2=a2[i2];
			continue;
		}
	}
	cout<<ans;
	return 0;
}