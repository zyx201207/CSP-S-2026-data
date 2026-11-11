#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int n,m,a[200005],flag[200005];
string s[200005];
bool cmp(string a,string b){
	return a>b;
}
int ans=0;
int cifang(int a,int b){
	if(b==0) return 1;
	int ans=a;
	for(int i=1;i<b;i++){
		ans*=a;
	}
	return ans;
}
void fun1(){
	for(int i=1;i<=n;i++){
		int x=a[i];
		while(x!=0){
			int yu=x%2;
			if(yu==1){
				s[i]="1"+s[i];
			}
			else{
				s[i]="0"+s[i];
			}
			x/=2;
		}
	}
	sort(s+1,s+n+1,cmp);
	int maxlen=0;
	for(int i=1;i<=m;i++){
		int len=s[i].size();
		maxlen=max(maxlen,len);
	}
	for(int i=1;i<=m;i++){
		if(s[i].size()<maxlen){
			int len=s[i].size();
			while(len<maxlen){
				s[i]="0"+s[i];
				len++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int len=s[i].size();
		for(int j=0;j<len;j++){
			if(flag[j]==0)continue;
			if(s[i][j]=='0'){
				flag[j]=0;
			}
		}
	}
	int a=0;
	for(int i=maxlen-1;i>=0;i--){
		if(flag[i]!=0){
			ans+=cifang(2,a);
		}
		a++;
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(flag,0x3f,sizeof(flag));
	scanf("%d %d",&n,&m);
	int flag1=0; 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i-1) flag1=1;
	}
	if(flag1){
		fun1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		while(x!=0){
			int yu=x%2;
			if(yu==1){
				s[i]="1"+s[i];
			}
			else{
				s[i]="0"+s[i];
			}
			x/=2;
		}
	}
	int maxlen=0;
	for(int i=1;i<=n;i++){
		int len=s[i].size();
		maxlen=max(maxlen,len);
	}
	for(int i=1;i<=n;i++){
		if(s[i].size()<maxlen){
			int len=s[i].size();
			while(len<maxlen){
				s[i]="0"+s[i];
				len++;
			}
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=m;i++){
		int len=s[i].size();
		for(int j=0;j<len;j++){
			if(flag[j]==0)continue;
			if(s[i][j]=='0'){
				flag[j]=0;
			}
		}
	}
	int a=0;
	for(int i=maxlen-1;i>=0;i--){
		if(flag[i]!=0){
			ans+=cifang(2,a);
		}
		a++;
	}
	cout<<ans;
	return 0;
}
