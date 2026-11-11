#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const int N=2e5+10;
struct node{
	long long l,r,len;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].len>>s[i].c;
		s[i].l=m+1;
		m+=s[i].len;
		s[i].r=m;
	}
	long long j=n;
	for(int i=1;i<=n;i++){
		long long sr=m-s[i].l+1;
		long long sl=m-s[i].r+1;
		if((sl>=s[i].l&&sr<=s[i].r)||(sr>=s[i].l&&sr<=s[i].r)||sr<=s[i].l){
			break;
		}
		
		for(;j>=1;){
			long long ul=s[j].l,ur=s[j].r;
		//	cout<<ul<<" "<<ur<<" "<<sl<<" "<<sr<<"\n";
			if((ul>=sl)&&(ur<=sr)){//°üº¬ 
				if(s[i].c!=s[j].c){
					ans+=s[j].len;
				}
				j--;
			}else if(ul<=sl&&ur>=sl&&ur<=sr){//×ó²àÒç³ö 
				if(s[i].c!=s[j].c){
					ans+=ur-sl+1;
				}
				break;
			}else if(ul>=sl&&ur>=sr&&ul<=sr){//ÓÒ²àÒç³ö 
				if(s[i].c!=s[j].c){
					ans+=sr-ul+1;
				}
				j--;
			}else if(ul<=sl&&ur>=sr){//±»°üº¬ 
				if(s[i].c!=s[j].c){
			//		cout<<2<<"\n";
					ans+=s[i].len; 
				}
				break;
			}
			if(ul<=sl&&ur<=sl)break;
		//	cout<<ans<<"\n";
		//	return  0;
		}
		
	//	cout<<i<<" "<<j<<" "<<sl<<" "<<sr<<" "<<s[i].l<<" "<<s[i].r<<"\n";
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a 1~1000000000
1000000000 a 1000000001~2000000000
1000000000 a 
1000000000 b
1000000000 b
1000000000 b
1 5 5000000001 6000000000 4000000001 5000000000
*/
