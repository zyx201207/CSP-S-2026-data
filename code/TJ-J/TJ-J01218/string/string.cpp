#include<bits/stdc++.h>
using namespace std;
long long n,num=1,sum=0,ans=0,cc,jo;
string s,r,acgo;
long long k[100000005];
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i]>>c[i];
		while(k[i]--) s+=c[i];
	}
	
	sum=s.size();
	if(sum%2==1) jo=1;//ÅÐ¶ÏÆæÅ¼Êý£» 
	for(int i=1;i<=sum/2;i++) r[i]=s[i];//¸³Öµ¸ør£» 
	for(int i=sum/2+jo+1;i<=sum;i++) acgo[i]=s[i];
	for(int j=1;j<=sum/2;j++){
		if(r[j]!=acgo[j]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
