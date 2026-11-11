#include<bits/stdc++.h>
using namespace std;
string s;
long long n,cnt;
struct stu{
	long long x;
	char c;
}a[200005];
long long sum[200005];
int head=1,tail;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		sum[i]=sum[i-1]+a[i].x;
	}
	tail=n;
	while(head<=tail){
		if(head==tail){
			cnt+=a[head].x;
			break; 
		}
		if(a[head].c==a[tail].c){
			if(a[head].x==a[tail].x){
				cnt+=a[tail].x;
				cnt+=a[head].x;
				head++;
				tail--;
			}
			else if(a[head].x>=a[tail].x){
				a[head].x-=a[tail].x;
				cnt+=a[tail].x;
				cnt+=a[tail].x;
				tail--;
			}
			else if(a[head].x<=a[tail].x){
				cnt+=a[head].x;
				cnt+=a[head].x;
				a[tail].x-=a[head].x;
				head++;
			}
		}
		else{
			if(a[head].x==a[tail].x){
				head++;
				tail--;
			}
			else if(a[head].x>=a[tail].x){
				a[head].x-=a[tail].x;
				tail--;
			}
			else if(a[head].x<=a[tail].x){
				a[tail].x-=a[head].x;
				head++;
			}
		}
	}
	cout<<(sum[n]-cnt)/2;
	return 0;
}
