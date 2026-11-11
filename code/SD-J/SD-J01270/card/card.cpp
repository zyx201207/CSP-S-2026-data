#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,a[1000000],b,cnt[1000000],cnt1[1000000],res;
string s="",s1;
double t;
bool vis;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s="";
		for(int j=i;j<=n;j++){
			int j1=a[j];
			s1="";
			while(j1){
				s1+=j1%10+'0';
				j1/=10;
			}
			if(s.find(s1)<=s.size()){
				s.insert(s.find(s1),'\0');
			}else{
				s+=s1;
				s+=' ';
			}
		}
		int k=0;
		for(int j;j<=s.size();j++){
			if(s[j]!=' ') cnt[k]=cnt[k]*10+s[j]-'0';
			else k++;
		}
		for(int j=0;j<k;j++){
			cnt1[cnt[j]]++;
		}
	}
	for(int i=0;i<=m;i++){
		if(cnt1[i]) cout<<cnt1[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
























