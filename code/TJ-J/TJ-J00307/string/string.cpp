#include<bits/stdc++.h>
using namespace std;
long long n;
char a[10000010];
struct Num{
	long long a;
	char c;
};
Num s[1000010];
bool f=true,l=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<n-1;i++){
		if(s[i].c!=s[i+1].c){
			l=false;
			break;
		}
	}
	if(l==true){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<n-1;i++){
		if(s[i].a!=s[i+1].a){
			f=false;
			break;
		}
	}
	if(f==true){
		long long q=0,h=n-1,sum=0;
		for(long long i=0;i<n/2;i++){
			if(s[q].c!=s[h].c) sum++;
			q++;
			h--;
		}
		cout<<sum*s[0].a;
		return 0;
	}
	long long d=0;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<s[i].a;j++){
			a[d]=s[i].c;
			d++;
		}
	}
 	long long q1=0,h1=d-1,sum1=0;
	for(long long i=0;i<d/2;i++){
		if(a[q1]!=a[h1]) sum1++;
		q1++;
		h1--;
	}
	cout<<sum1;
	return 0;
}
