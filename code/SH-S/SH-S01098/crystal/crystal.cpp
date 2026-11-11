#include<bits/stdc++.h>
using namespace std;


long long a[500001];

queue<long long> q;


bool cmp(long long a,long long b){
	return a<b;
}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	long long n,m,delta,mx=0,sum=0,currnum=0;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1,cmp);
	for (int i=2;i<=n;i++) {
        delta=a[i]-a[i-1];
        //cout << a[i-1] << endl;
        //cout << delta << endl;
        q.push(a[i-1]);
        currnum+=1;
        sum+=delta*currnum;
        //cout << "sum" << sum;
        while (sum>m) {
            sum-=(a[i]-q.front());
            //cout << "frontofq" <<q.front();
            q.pop();
            currnum-=1;
        }
        //cout << "currnum" <<  currnum << endl;
        mx=max(mx,currnum+1);

	}

	cout << mx << endl;


	return 0;
}
