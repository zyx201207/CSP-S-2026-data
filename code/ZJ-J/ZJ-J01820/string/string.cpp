#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long sum=0;
struct Ch{
	int id;
	char c;
	long long num;
} a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].num >> a[i].c;
		a[i].id=i;
	}
	Ch qian,hou;
	qian=a[1];
	hou=a[n];
	while(qian.id<hou.id){
		if(qian.c!=hou.c){
			long long t=min(qian.num,hou.num);
			qian.num-=t;
			hou.num-=t;
			sum+=t;
			if(qian.num==0){
				qian=a[qian.id+1];
			}
			if(hou.num==0){
				hou=a[hou.id-1];
			}
		}else{
			long long t2=min(qian.num,hou.num);
			qian.num-=t2;
			hou.num-=t2;
			if(qian.num==0){
				qian=a[qian.id+1];
			}
			if(hou.num==0){
				hou=a[hou.id-1];
			}
		}
	}
	cout << sum;
	return 0;
}
