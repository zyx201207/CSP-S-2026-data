#include<bits/stdc++.h>
#define kll long long
using namespace std;
const int N=2e5+5;
kll m,n,a[N];
kll sum[40];//每一位出现了多少次 ,2^0,2^1~~
//________________________________________
kll p[N],up=1,e_p[N],e_up=1;//可能参加的数 
kll s_sum,z_sum;//最大可能，最小可能 
void cdd(kll n){
	kll idx=0;
	while(n){
		sum[idx]+=n%2;
		n/=2;
		idx++;
	}
}
void add(kll c){
	kll d=c;
	for(int i=1;i<=n;i++) {
		kll opeee=a[i];
		d=c;
		while(d){
			opeee/=2;
			d--;
		}
		if(opeee%2==1) p[up++]=a[i];
	}
}
bool calc(kll c){//二进制c位上有没有数字 
	kll sum=0,d=c;
	for(int i=1;i<=up;i++){
		kll opeee=p[i];
		d=c;
		while(d){
			opeee/=2;
			d--;
		}
		if(opeee%2==1){
			sum++;
			e_p[e_up++]=p[i];
		} 
	}
	if(sum>=m){//转移 
		up=e_up-1;
		for(int i=1;i<=up;i++) p[i]=e_p[i];
		e_up=1;
		return 1;
	}else {
		e_up=1;
		return 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cdd(a[i]); 
	}
	sort(a+1,a+1+n,greater<int>());
	if(m==1){
		cout<<a[1]<<' ';
		return 0;
	}else if(m==n){
		kll b=a[1];
		for(int i=1;i<=n;i++) b=(b&a[i]);
		cout<<b;
		return 0;
	}
	kll idx=0;//以前有没有国 
	for(int i=30;i>=0;i--){
		if(sum[i]>=m){
			if(idx==0){
				s_sum+=(kll) pow(2,i);
				add(i);
				idx++; 
			}
			else if(calc(i)){//二进制i位上有没有数字 
				s_sum+=(kll) pow(2,i);
			}
		}
	} 
	cout<<s_sum;
	return 0;
	/* 
	100+100+100+0
	*/
}

