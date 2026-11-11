#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<climits>
using namespace std;
long long n,m,minium=LLONG_MAX,tt=0;
char ch;
struct fri{
	long long m;
	char c;
}friends[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>friends[i].m>>friends[i].c;
	}
	long long i=0,j=n-1;
	long long cnt=n;
	while(i<j&&cnt>1){
		minium=min(friends[i].m,friends[j].m);
		if(friends[i].c!=friends[j].c){
			tt+=minium;
		}
		friends[i].m-=minium;
		friends[j].m-=minium;
		if(friends[i].m==0)i++,cnt--;
		if(friends[j].m==0)j--,cnt--;
	}
	cout<<tt;
	return 0;
}
