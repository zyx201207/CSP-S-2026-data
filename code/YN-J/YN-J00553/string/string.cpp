#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,a[N],b[N];
char ch[N];
long long j,ans,leni,lenj,len;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>ch[i],b[i]=a[i],len+=a[i];
	j=n;
	long long i=1;
	while(leni<len/2){
		leni+=a[i];
		if(leni>len/2){
			long long last=leni;
			leni=len/2;
			b[i]=last-leni;
		}
		while(lenj<=leni){
			lenj+=b[j];
			if(lenj>leni)break;
			if(ch[j]!=ch[i])ans+=b[j];
			j--;
		}
		lenj-=b[j];
		int last=b[j];
		b[j]=b[j]-(leni-lenj);
		if(ch[j]!=ch[i])
			ans+=last-b[j];
		lenj=leni;
		i++;
	}
	cout<<ans;
	return 0;
}
