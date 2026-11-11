#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long sum;
struct node{
	int s;
	char c;
}a[N],s1[N],s2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		sum+=a[i].s;
	}
	long long cnt=0;
	int flag=0;
	for(int i=1;i<=n&&cnt<=sum/2;i++){
		cnt+=a[i].s;
		flag=i;
	}
//	cout<<cnt;
	cnt-=a[flag].s;
	for(int i=1;i<flag;i++){
		s1[i].s=a[i].s;
		s1[i].c=a[i].c;
	}
	s1[flag].s=(sum/2)-cnt;
	s1[flag].c=a[flag].c;
	cnt=0;
	for(int i=n;i>flag;i--){
		cnt+=a[i].s;
		s2[n-i+1].s=a[i].s;
		s2[n-i+1].c=a[i].c;
	}
	flag--;
	s2[n-flag].s=(sum/2)-cnt;
	s2[n-flag].c=a[flag+1].c;
	long long ans=0;
	for(int i=1,j=1;i<=flag,j<=n-flag;){
		if(s1[i].c==s2[j].c){
			if(s1[i].s>s2[j].s){
				s1[i].s-=s2[j].s;
				j++;
			}
			else if(s1[i].s<s2[j].s){
				s2[j].s-=s1[i].s;
				i++;
			}
			else{
				i++;j++;
			}
		}
		else{
			if(s1[i].s>s2[j].s){
				s1[i].s-=s2[j].s;
				ans+=s2[j].s; 
				j++;
			}
			else if(s1[i].s<s2[j].s){
				s2[j].s-=s1[i].s;
				ans+=s1[i].s; 
				i++;
			}
			else{
				ans+=s1[i].s; 
				i++;j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
