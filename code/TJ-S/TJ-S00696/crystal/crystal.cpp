#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int cnt,sz,msz;
long long a[500005],l,r;
queue<long long>q;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long tmp=m;
	q.push(0);
	msz++;
	long long p=a[1];
	for(int i=2;i<=n;i++){
		int num=q.size();
		long long ct=(a[i]-a[i-1]);
		if(tmp-ct*num>=0){
			p=p+a[i]-a[i-1];
			tmp-=ct*num;
			q.push(a[i]-a[i-1]-p);
			num++;
			msz=max(msz,int(q.size()));
		}else{
			while(tmp-ct*num<0){
				tmp=tmp+q.front()+p;
				q.pop();
				num--;
			}
			tmp-=ct*num;
			p=p+a[i]-a[i-1];
			q.push(a[i]-a[i-1]-p);

		}
	}
	msz=max(msz,int(q.size()));
	cout<<msz<<endl;
	
	return 0;
}
