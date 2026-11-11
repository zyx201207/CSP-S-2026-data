#include<bits/stdc++.h>
using namespace std;
long long n,now1,now2,nowid1,nowid2;
long long ans;
long long a1[200005],a2[200005];
char c1[200005],c2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>c1[i];
		a2[n-i+1]=a1[i];
		c2[n-i+1]=c1[i];
	}
	while(1){
		if(nowid1==n&&now1==0){
			break;
		}
		if(now1==0){
			nowid1++;
			now1+=a1[nowid1];
		}
		if(now2==0){
			nowid2++;
			now2+=a2[nowid2];
		}
		if(c1[nowid1]!=c2[nowid2]){
			int cha=min(now1,now2);
			ans+=cha;
			now1-=cha;
			now2-=cha;
		}else{
			int cha=min(now1,now2);
			now1-=cha;
			now2-=cha;
		}
	}
	cout<<(ans+1)/2;
	return 0;
}
