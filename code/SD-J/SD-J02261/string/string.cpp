#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
long long n;
unsigned long long ans=0;
const int M=1000000;
struct node{
	long long l;
	char c;
}a[M];
long long llen;
char lch;
long long len;
char ch;
long long p=1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	long long m=n;
	cin>>llen>>lch;
	/*
	cout<<"*"<<llen<<" "<<lch<<endl<<p<<endl;
	for(long long i=1;i<p;i++)
		cout<<a[i].l<<' '<<a[i].c<<' ';
	cout<<endl;
	
	//*/
	for(long long i=2;i<=n;i++){
		/*
		cout<<i<<' '<<llen<<' '<<lch<<endl<<p<<endl;
		for(long long i=1;i<p;i++)
			cout<<a[i].l<<a[i].c;
		cout<<endl;
		//*/
		cin>>len>>ch;
		if(ch==lch){
			llen+=len;
			//cout<<"->";
			continue;
		}
		
		a[p].c=lch;
		a[p].l=llen;
		llen=len;
		lch=ch;
		p++;
	}
	a[p].c=lch;
	a[p].l=llen;
	/*
	cout<<llen<<' '<<lch<<endl<<p<<endl;
	for(long long i=1;i<=p;i++)
		cout<<a[i].l<<a[i].c;
	cout<<endl;
	//*/
	long long pl=1,pr=p;
	//cout<<pl<<" "<<pr<<" "<<a[pl].l<<a[pl].c<<" "<<a[pr].l<<a[pr].c<<" "<<ans<<" "<<endl;
	while(pl!=pr){
		
		if(a[pl].l==0)pl++;
		if(a[pr].l==0)pr--;
		long long v=min(a[pl].l,a[pr].l);
		//cout<<pl<<" "<<pr<<" "<<a[pl].l<<a[pl].c<<" "<<a[pr].l<<a[pr].c<<" "<<v<<" "<<" "<<ans<<" "<<endl;
		if(a[pr].c!=a[pl].c){
			ans+=v;
		}
		//cout<<pl<<" "<<pr<<" "<<a[pl].l<<a[pl].c<<" "<<a[pr].l<<a[pr].c<<" "<<v<<" "<<" "<<ans<<" "<<endl;
		a[pl].l-=v;
		a[pr].l-=v;
		//cout<<pl<<" "<<pr<<" "<<a[pl].l<<a[pl].c<<" "<<a[pr].l<<a[pr].c<<" "<<" "<<v<<" "<<ans<<" "<<endl;
		
		
	}
	cout<<ans;
	
	
	
	return 0;
} 


//gunmu otto shuai




/*
3
2 a
2 b
1 c

2
*/

/*
2
2 a
3 a

0
*/


/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000




*/
