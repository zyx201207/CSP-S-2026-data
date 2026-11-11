#include<bits/stdc++.h>
using namespace std;

struct node{
	long long num;
	char word;
};
node p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>p[i].num;
		cin>>p[i].word;
	}
	long long L=1,R=n,cnt=0;
	long long l=p[L].num,r=p[R].num;
	while(L<R){
		long long temp=min(l,r);
		if(p[L].word!=p[R].word){
			cnt+=temp;
		}
		l-=temp;
		r-=temp;
		if(l>r){
			R--;
			r+=p[R].num;
		}
		else{
			L++;
			l+=p[L].num;
		}
		
	}
	cout<<cnt;
	//¼ÇµÃ¸Älong long 
	return 0;
}
