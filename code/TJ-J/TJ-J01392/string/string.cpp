#include<bits/stdc++.h>
using namespace std;
struct int1{
	long long a;
	char b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
long long n;
int a[26]={0};

cin>>n;
long long sum=0;
char mid;
int1 max;
max.a=-1;
for(int i=0;i<n;i++){
	int1 kind;
	cin>>kind.a>>kind.b;
	sum+=kind.a;
	a[kind.b-'a']+=kind.a;
    if(kind.a>max.a){
    	max.a=kind.a;
    	max.b=kind.b;
	}
}
if(sum%2==0||a[max.b-'a']==sum){
	cout<<sum-a[max.b-'a'];
}else{
	cout<<sum-(a[max.b-'a']+1);
}
	return 0;
}
