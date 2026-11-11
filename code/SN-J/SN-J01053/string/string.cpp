#include<bits/stdc++.h>
using namespace std;

const long long MAXN=500;
long long n,a[MAXN],sum,small,big,mid,ans;
struct A{
	long long d;
	char word;
}c[MAXN]; 

void add(long long r,long long l){
	ans+=l-r;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i].word;
		sum+=a[i];
		c[i].d =sum;
	}
	int i=0,j=0;
	while(n-i>i){
		
		if(sum-c[n-j].d==c[i].d){
			
			if(sum-c[n-j-1].d<c[i+1].d){
				j++;
				big=sum-c[n-j].d;
				small=c[i].d;
			}else{
				i++;
				big=c[i].d;
				small=sum-c[n-j].d;
			}
			if(c[i].word==c[n-i].word) add(small,big);
		}if(sum-c[n-j].d>c[i].d){
			i++;
			small=min(c[i].d,sum-c[n-j].d);
			big=max(c[i].d,sum-c[n-j].d);
			if(c[i].word==c[n-i].word) add(small,big);
		}if(sum-c[n-j].d<c[i].d){
			j++;
			small=min(c[i].d,sum-c[n-j].d);
			big=max(c[i].d,sum-c[n-1].d);
			if(c[i].word==c[n-i].word) add(small,big);
		}
		
	}
	cout<<ans;
	return 0;
	
}
