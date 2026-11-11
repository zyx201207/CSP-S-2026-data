#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
long long n,m,a[200005],cnt,ans;
string s[200005];
bool pd[200005],p[200005];
string chge(long long x){
	string str="";
	while(x>0){
		str=char(x%2+'0')+str;
		x/=2;
	}
	return str;
}
int main(){
//	freopen("and5.in","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=chge(a[i]);
		while(s[i].size()<35){
			s[i]='0'+s[i];
		}
//		cout<<s[i]<<endl;
	}
	for(int i=0;i<35;i++){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(!pd[j]){
				if(s[j][i]=='1'){
					p[j]=true;
					cnt++;
				}
			}
		}
//		cout<<endl;
		if(cnt>=m){
//			cout<<i<<endl;
			ans=ans+(1<<(34-i));
			for(int j=1;j<=n;j++){
				if(!p[j]){
					pd[j]=true;
				}
				p[j]=false;
			}
		}
	}
	cout<<ans;
	return 0;
}
