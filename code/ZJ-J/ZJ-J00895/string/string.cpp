#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct KP{
	int num;
	char chr;
};
KP a[maxn],l[maxn],r[maxn];
long long mid,cnt,ans;
int n,lid=1,rid;
int read_(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while( isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
//void check(){
//	cout<<lid<<' '<<rid<<' '<<mid<<'\n';
//	cout<<"---\n";
//	for(int i=0;i<=lid;i++) cout<<l[i].num<<' '<<l[i].chr<<'\n';
//	cout<<"---\n";
//	for(int i=0;i<=n;i++) cout<<r[i].num<<' '<<r[i].chr<<'\n';
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read_();
	for(int i=1;i<=n;i++){a[i].num=read_();cin>>a[i].chr;}
	for(int i=1;i<=n;i++) cnt+=a[i].num;
	mid=cnt/2;
	for(long long ct=0;lid<=n;lid++){
		ct+=a[lid].num;
		if(ct<=mid) l[lid].num=a[lid].num,l[lid].chr=a[lid].chr;
		else{
			l[lid].num=mid-ct+a[lid].num;
			a[lid].num=ct-mid;
			l[lid].chr=a[lid].chr;
			break;
		}
	}
	rid=lid;
	for(bool flag=true;rid<=n;rid++){
		if(a[rid].num==0) continue;
		if(flag&&cnt%2==1) a[rid].num--,flag=false;
		r[rid].num=a[rid].num;
		r[rid].chr=a[rid].chr;
	}
	rid=lid;if(a[rid].num==0) rid++;
//	check();
	while(true){
		if(l[lid].chr==r[rid].chr){
			if(l[lid].num>r[rid].num){
				l[lid].num-=r[rid].num;
				rid++;
			}
			else if(l[lid].num==r[rid].num){
				lid--;
				rid++;
			}
			else{
				r[rid].num-=l[lid].num;
				lid--;
			}
		}
		else{
			if(l[lid].num>r[rid].num){
				l[lid].num-=r[rid].num;
				ans+=r[rid].num;
				rid++;
			}
			else if(l[lid].num==r[rid].num){
				ans+=l[lid].num;
				lid--;rid++;
			}
			else{
				r[rid].num-=l[lid].num;
				ans+=l[lid].num;
				lid--;
			}
		}
		if(lid==0) break;
	}
	cout<<ans;
	return 0;
}
