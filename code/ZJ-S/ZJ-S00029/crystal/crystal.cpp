#include<bits/stdc++.h>
using namespace std;
const int INF=1e12+5;
long long rd(){
	long long m=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=!f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		m=m*10+ch-'0';
		ch=getchar();
	}
	return m*f;
}
void wr(long long num){
	if(num==0){
		return ;
	}
	if(num<0){
		putchar('-');
		num=(-num);
	}
	wr(num/10);
	putchar(num%10+'0');
}
long long n,m,a[500005],ans=0;
long long L=INF,R=-INF;
int find(long long sc){
	for(int i=n;i>=1;i--){
		if(a[i]<=sc) return i;
	}
	return 0;
}
bool check(long long mid){
	int id=find(mid);
	if(id==0) return 1;
	bool flag=0;
	long long total=0,sum=0;
	for(int i=id;i>=1;i--){
		total+=mid-a[i];
//		cout<<total<<" ";
		if(total>m) break;
		sum++;
	}
	if(sum<=ans) flag=1;
	else ans=sum; 
	return flag;
}
int main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	bool allsame=1,kksk;
	for(int i=1;i<=n;i++){
		a[i]=rd();
		if(i==1) kksk=a[i];
		if(a[i]>R){
			R=a[i];
		}
		if(a[i]<L){
			L=a[i];
		}
		if(kksk!=a[i]) allsame=0; 
	}
	if(allsame){
		wr(n);
		return 0;
	}
//	cout<<L<<' '<<R;
	sort(a,a+n+1);
//	for(int i=1;i<=n;i++){
//		wr(a[i]);
//		putchar(' ');
//	}
	while(L<R){
		long long mid=(L+R)/2;
		if(check(mid)){
			L=mid+1;
		}else{
			R=mid;
		}
//		cout<<L<<" "<<R<<endl;
//		wr(check(mid));
	}
	if(ans==0){
		putchar('0');
		return 0;
	}
	wr(ans);
	return 0;
}
