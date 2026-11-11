#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Node{
	int num;
	char c;
}a[N];
Node s1[N];
Node s2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		len+=a[i].num;
	}
	long long sum=0,mid=(len>>1),j=1,t=1;
	while(sum+a[j].num<=mid){
		int p=a[j].c-'a'+1;
		s1[t].num+=a[j].num;
		s1[t++].c=a[j].c;
		sum+=a[j].num;
		
		j++;
	}
	s1[t].num+=(mid-sum);
	s1[t].c=a[j].c;
	int ted=t;
	t=1;
	s2[t].num+=a[j].num-(mid-sum);
	s2[t++].c=a[j].c;
	j++;
	while(j<=n){
		s2[t].num+=a[j].num;
		s2[t++].c=a[j].c;
		j++;
	}
//	for(int i=1;i<=ted;i++) cout<<s1[i].c<<' '<<s1[i].num<<"\n";
//	cout<<"\n";
//	for(int i=1;i<t;i++) cout<<s2[i].c<<' '<<s2[i].num<<"\n";
	long long ans=0;
	for(int i1=1,i2=t-1;i1<=ted,i2>=1;i1++,i2--){
		if(s1[i1].c!=s2[i2].c){
			ans+=min(s1[i1].num,s2[i2].num);
			if(s1[i1].num>s2[i2].num){
				s1[i1].num-=s2[i2].num;
				i1--;
			}
			else{
				s2[i2].num-=s1[i1].num;
				i2++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
