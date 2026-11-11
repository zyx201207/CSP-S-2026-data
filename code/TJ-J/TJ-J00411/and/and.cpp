#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool b[200005];
string s[200005];
int l=0;
long long ans=0;
bool cmp(long long a,long long b){
	return a>b;
}
string zhu(long long num){
	int i=0;
	string st="";
	while(1){
		if(i>=l && num==0){
			break;
		}
		i++;
		if(num%2!=0)
			st+='1';
		else
			st+='0';
		num/=2;
	}
	l=max(l,i);
	return st;
}
void hui(string anss){
	int i=0;
	while(anss.size()>i){
		i++;
		long long num=1;
		for(int k=1;k<i;k++){
			num*=2;
		}
		ans+=(anss[i-1]-48)*num;
	}
}
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=zhu(a[i]);
		reverse(s[i].begin(),s[i].end());
	}
	string anss="";
	for(int i=0;i<l;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='1' &&  b[j]==0)
				t++;
		}
		if(t>=m){
			for(int j=1;j<=n;j++){
				if(s[j][i]!='1')
					b[j]=1;
			}
			anss+='1';
		}
		else
			anss+='0';
	}  
	reverse(anss.begin(),anss.end());
	hui(anss);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
