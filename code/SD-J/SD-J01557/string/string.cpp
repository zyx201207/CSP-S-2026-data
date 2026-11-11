#include<bits/stdc++.h>
#define kll long long
using namespace std;
const int N=3e5+5;
struct node{
	kll num;
	char u;
}a[N];
int n;
kll s_num,l=1,r;// 左右进行到哪了 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].u;
	}
	r=n;
	kll l_siz=a[1].num,r_siz=a[n].num;//当前左右剩的 
	while(l<r){
		if(a[l].u==a[r].u){
			if(l_siz>r_siz){
				l_siz-=r_siz;
				r--,r_siz=a[r].num;
			}else if(l_siz<r_siz){
				r_siz-=l_siz;
				l++,l_siz=a[l].num;
			}else{
				l++,r--;
				l_siz=a[l].num,r_siz=a[r].num;
			}// 		相等的情况 
		}else{
			if(l_siz>r_siz){
				l_siz-=r_siz;
				s_num+=r_siz;
				r--,r_siz=a[r].num;
			}else if(l_siz<r_siz){
				r_siz-=l_siz;
				s_num+=l_siz;
				l++,l_siz=a[l].num;
			}else{
				l++,r--;
				s_num+=l_siz;
				l_siz=a[l].num,r_siz=a[r].num;
			}
		}
	}
	cout<<s_num;
	return 0;
}
