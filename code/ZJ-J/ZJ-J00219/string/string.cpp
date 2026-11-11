#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],p[N],d[N],n,ans=0,tot=0;
char s[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		tot+=a[i];
		p[i]=p[i-1]+a[i];
	}
	d[n+1]=0;
	for(int i=n;i>=1;i--){
		d[i]=d[i+1]+a[i];
	}
//	for(int i=1;i<=n;i++) cout<<p[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<d[i]<<' ';
//	cout<<endl;
	int idx1=a[1],idx2=tot+1-a[n];
	int ii1=1,ii2=1,last1=a[1],last2=a[n];
	char s1=s[1],s2=s[n];
	int gg;
	while(idx1<idx2){
		gg=min(last1,last2);
		if(s1!=s2){
//			cout<<ii1<<' '<<ii2<<"   "<<idx1<<' '<<idx2<<"   "<<last1<<' '<<last2<<' '<<gg<<"   ";
			ans+=gg;
//			cout<<ans<<endl;
		}
		if(last1==last2){
			ii1++,ii2++;
			idx1=p[ii1],idx2=tot+1-d[n+1-ii2];
			last1=a[ii1],last2=a[n+1-ii2];
			s1=s[ii1],s2=s[n+1-ii2];
		}
		else if(last1<last2){
			ii1++;
			idx1=p[ii1];
			last1=a[ii1];
			last2-=gg;
			s1=s[ii1];
		}
		else{
			ii2++;
			idx2=tot+1-d[n+1-ii2];
			last2=a[n+1-ii2];
			last1-=gg;
			s2=s[n+1-ii2];
		}
//		cout<<ii1<<' '<<ii2<<"   "<<idx1<<' '<<idx2<<"   "<<last1<<' '<<last2<<' '<<gg<<endl<<endl;
//		Sleep(1000);
	}
	cout<<ans;
	return 0;
}
// 9 1 a 2 d 3 f 10 g 55 d 10 g 3 f 2 d 1 a