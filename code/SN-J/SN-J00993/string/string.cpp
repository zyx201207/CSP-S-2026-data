#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n;
struct num{
	long long a;
	char signn;
}str[N];
long long had[N],times=0;
bool flag=true;


long long maxfi(long long x){
	int k=n-2;
	long long r=1,maxx=had[k];
	if(x<had[k])	return k;
	while(x>maxx){
		maxx=had[--k];
		r=had[k+1];
	}
 	return r;
}


char findback(long long x){
	if(str[x].a!=0)	return str[x].signn;
	sort(had+1,had+n+1);
	if(x<had[1])	return str[had[1]].signn;
	if(x>had[n-1])	return	str[had[n]].signn;
	return str[maxfi(x)].signn;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long x=0,l;
	char c,oldc;
	for(int i=1;i<=n;i++){
		cin>>l>>c;
		x+=l;
		had[i]=x;
		str[x].a=l;
		str[x].signn=c;
		if(flag){
			oldc=str[had[i-1]].signn;
			if(oldc!=c)	flag=false;
		}
	}
	if(flag||n==1){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=n/2;i++){
		if(findback(i)!=findback(1+n-i)) times++;
	}	
	cout<<times<<endl;
	return 0;
}
