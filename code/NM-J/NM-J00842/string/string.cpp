#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
int li,ri;
struct edge{
	int a;
	char c;
};
edge l;
edge r;
edge a[N];
int x,ans,m;
char y;
/*
	shi nian oi yi chang kong , bu kai long long jian zu zong
	2e5 shu ju gui mo hai si wo le!
	* xi wang wo neng da 250 yi shang
	* 				*********
	* 			    *		*
	* 				* R.I.P.*
	* 				*		*
	* 				*		*
	* 			******************
	* oi guan fang fang guo wo , qiu qiu le
*/
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int k=0;
    a[k].c='.';
    for(int i=1;i<=n;i++){
		cin>>x>>y;
		m+=x; //ji suan zong shu
		if(y==a[k].c){
			a[k].a+=x;
		}else{
			k++;
			a[k].a=x;
			a[k].c=y;
		}
	}
	//hebing (correct)
	ri=k;
	li=1;
	while(li<ri){
		l.a=a[li].a;
		l.c=a[li].c;
		r.a=a[ri].a;
		r.c=a[ri].c;
		if(l.a==r.a){
			if(l.c==r.c){
				li++;
				ri--;
			}else{
				li++;
				ri--;
				ans+=l.a;
			}
		}
		else if(l.a>r.a){
			if(l.c==r.c){
				ri--;
				a[li].a-=r.a;
			}
			else{
				ri--;
				a[li].a-=r.a;
				ans+=r.a;
			}
		}else{
			if(l.c==r.c){
				li++;
				a[ri].a-=l.a;
			}
			else{
				li++;
				a[ri].a-=l.a;
				ans+=l.a;
			}
		}
	}
	cout<<ans;
    return 0;
	//ni guo guan!
}
