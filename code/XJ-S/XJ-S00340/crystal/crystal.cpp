#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500010],b[500010];
bool cmp(long long x,long long y){
	return x<y;
}
bool judge(int j){
	for(int i=1;i<=n;i++){
		if(a[i]==j) return 1;
		if(a[i]>j) return 0;
	}
	return 0;
}
long long work(int i){
	long long left=m,sum=0;
	for(long long j=a[1];j<i+1;j++){
		if((left+a[j]>=i&&judge(j))||a[j]==i){
			left=left-i+j;
			sum++;
			cout<<j<<" "<<sum<<" "<<left<<"  ";
		}
	}
	cout<<endl;
	return sum;
}
void s(){
	long long min=10e14,p=1,num=1;
	for(long long i=1;i<=n;i++){
		min=10e14,p=1;
		for(long long j=num;j<=n;j++){
			if(a[j]<min){
				min=a[j];
				p=j;
			}
		}
		swap(a[num],a[p]);
		num++;
		//cout<<min<<"  ";
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long min=10e8,f,s;
	for(long long i=1;i<=n;i++){
		if(a[i]<min){
			min=a[i];
			f=i;
		}
	}
	sort(a,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			a[i]==min;
			while(i>=1){
				swap(a[i-1],a[i]);
				i--;
			}
			break;
		}
	}
	//s();
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	//cout<<a[1];
	long long cha=a[2]-a[1],wr=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cha) wr=0;
	}
	if(wr=1){
		for(int i=1;i<=n;i++){
			if(m-cha*i>=0){
				m-=cha*i;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(long long i=a[1];i<=a[n];i++){
		ans=max(ans,work(i));
		//cout<<ans<<endl;
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	for(long long i=2;i<=n;i++){
//		b[i]=a[i]-a[i-1];
//	}
//	for(long long i=2;i<=n;i++){
//		if(m>b[i]){
//			
//		}
//	}
	cout<<ans;
	return 0;
}
//5 8
//-3 -1 2 2 7
//5 5
//1 2 4 8 9
//5 5
//-100 -200 0 -300 -400
