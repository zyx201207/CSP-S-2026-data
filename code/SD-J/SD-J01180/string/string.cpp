#include <bits/stdc++.h>
#define int long long
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define Auto(v,a) for(auto v:a)
#define ps() putchar(' ')
#define pe() putchar('\n')
using namespace std;
const int N=2e5+10;
void read(int &x){
	int a=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar()){
		if(c=='-'){
			f=-1;
		}
	}
	for(;isdigit(c);c=getchar()){
		a=a*10+c-48;
	}
	x=a*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
bool f(string s){
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			return false;
		}
	}
	return true;
}
struct node{
	int num;
	char c;
}a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	bool flag=true;
	cin>>n;
	rep(i,1,n){
		cin>>a[i].num>>a[i].c; 
	}
	rep(i,1,n-1){
		if(a[i].c!=a[i+1].c){
			flag=false;
		}
	}
	if(flag){
		write(0);
		return 0; 
	}
	for(int i=1,j=n;i<j;i++,j--){
		if((a[i].c!=a[j].c)&&(a[i].num==a[j].num)){
			a[j].c=a[i].c;
			sum+=a[i].num;
		}
		else{
			a[j].c=a[i].c;
			if(a[i].num>a[j].num){
				sum+=a[i].num;
				a[j-1].num-=(a[i].num-a[j].num);
			} 
			else{
				sum+=a[j].num;
				a[i+1].num-=(a[j].num-a[i].num);
			}
		}
	}
	write(sum);
	return 0;
}


