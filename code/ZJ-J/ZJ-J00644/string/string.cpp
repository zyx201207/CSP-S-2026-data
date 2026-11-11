#include<bits/stdc++.h>
using namespace std;
int n;
char ch[200005];
long long sum[200005],a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	long long l=1,r=0,pl=1,pr=n,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		sum[i]=sum[i-1]+a[i];
		r+=a[i];
	}
	while(l<=r){
		if(pl==pr) break;
		long long dl=sum[pl]-l+1,dr=r-sum[pr-1];
		if(dl<dr){
			if(ch[pl]!=ch[pr]) ans+=dl;
//			cout<<"l:"<<l<<" r:"<<r<<"\n";
			r=r-dl;
			l=sum[pl++]+1;
//			cout<<"l':"<<l<<" r':"<<r<<"\n";
		}else if(dl>dr){
			if(ch[pl]!=ch[pr]) ans+=dr;
//			cout<<"l:"<<l<<" r:"<<r<<"\n";
			l=l+dr;
			r=sum[--pr];
//			cout<<"l':"<<l<<" r':"<<r<<"\n";
		}else{
//			cout<<"l:"<<l<<" r:"<<r<<"\n";
			if(ch[pl]!=ch[pr]) ans+=dl;
			l=sum[pl++]+1;
			r=sum[--pr];
//			cout<<"l':"<<l<<" r':"<<r<<"\n";
		}
	}
	cout<<ans;

	return 0;
}
/*
6
4 a
1 b
1 a
1 b
2 a
2 a
01 02 03 04 05 06 07 08 09 10 11
 a  a  a  a  b  a  b  a  a  a  a
01 01 01 01 02 03 04 05 05 06 06 
*/
