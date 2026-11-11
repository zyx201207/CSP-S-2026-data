#include<bits/stdc++.h>
using namespace std;
long long a[200005],d,n,m,mi,k123;


long long n2[1005];
long long a1;
bool s[200005];
void f(int l,int x){
	if(l==n+1&&x==m){
		int d=2147483647;
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				d=d&a[i];
			}
		}
		if(d>mi){
			mi=d;
		}
		return ;
	}
	if(x==m){
		s[l]=0;
		f(l+1,x);
	}else{
		if(l-x-1==n-m){
			s[l]=1;
			f(l+1,x+1);
		}else{
			s[l]=0;
			f(l+1,x);
			s[l]=1;
			f(l+1,x+1);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2000){
		f(1,0);
		cout<<mi;
	}else{
		if(m==n-1){
			f(1,0);
			cout<<mi;
		}else{
			n2[1]=1;
			for(int i=2;i<=32;i++){
				n2[i]=n2[i-1]*2;
			}
			int o=0,o1=0;
			for(int i=1;i<=n;i++){
				if(a[i]!=n2[i]-1){
					o=1;
				}
				if(a[i]>4){
					o1=1;
				}
			}
			if(o==0){
				int gg=2147483647;
				for(int i=1;i<=m;i++){
					gg=gg&a[i];
				}
				cout<<gg;
			}else if(o1==0){
				int aa1,aa2,aa3,aa4;
				for(int i=1;i<=n;i++){
					if(a[i]==4){
						aa4++;
					}
					if(a[i]==3){
						aa3++;
					}
					if(a[i]==2){
						aa2++;
					}
					if(a[i]==1){
						aa1++;
					}
				}
				if(aa4>=2){
					cout<<4;
				}else if(aa3>=2){
					cout<<3;
				}else if(aa2>=2){
					cout<<2;
				}else if(aa1>=2){
					cout<<1;
				}
			}
		}
	}
	return 0;
}
/*
第三题了
求求让我60分吧！ 

emm..按位与，哦不 。 

写代码ing... 
写不出来。 

用点雷霆小妙招
特殊样例救我！
 
不是这个中文输入法好难受啊！
受不鸟啦~ 
*/
