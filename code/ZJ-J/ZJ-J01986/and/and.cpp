#include<bits/stdc++.h>
using namespace std;
typedef long long bro;
bro n,m,a[200005],b[50],ans,q = -1,o = -1;
vector<bro>x[50];
bro qpow(bro x,bro y){
	if(y == 0)return 1;
	if(y == 1)return x;
	bro cnt = qpow(x,y/2);
	cnt *= cnt;
	if(y%2 == 1)cnt *= x;
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;++i){
		cin>>a[i];
		bro p = a[i],cnt = 0;
		while(p){
			if(p%2 == 1){
				b[cnt]++;
				x[cnt].push_back(a[i]);
			}
			p /= 2;
			cnt++;
		}
	}
	for(int i = 0;i <= 30;++i){
		if(b[i] >= m)q = i;
		if(b[i] == m)o = i;
	}
	if(q == -1){
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(q != -1 && q == o){
		ans = x[q][0];
		for(int i = 1;i < x[q].size();++i){
			ans &= x[q][i];
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;	
	}
	ans += qpow(2,q);
	vector<bro>v;
	for(int i = 0;i < x[q].size();++i)v.push_back(x[q][i]);
	while(q){
		//cout<<q<<'*'<<ans<<endl;
		memset(b,0,sizeof(b));
		for(int i = 0;i <= 30;++i){
			x[i].clear();
		}
		for(int i = 0;i < v.size();++i){
			bro p = v[i],cnt = 0;
			while(p && v[i] >= ans){
				if(p%2 == 1){
					if(cnt < q)b[cnt]++;
					//cout<<cnt<<' ';
					if(cnt < q)x[cnt].push_back(a[i]);
				}
				p /= 2;
				cnt++;
			}
			//cout<<endl;
		}
		bro l = -1,k = -1;
		for(int i = 0;i < q;++i){
			if(b[i] >= m){
				l = i;
			}
			if(b[i] == m)k = i;
		}
		if(l == -1){
			cout<<ans;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		q = l;
		v.clear();
		for(int i = 0;i < x[q].size();++i)v.push_back(x[q][i]);
		if(l != -1 && l == k){
			ans = x[q][0];
			for(int i = 1;i < x[q].size();++i){
				ans &= x[q][i];
			}
			cout<<ans;
			fclose(stdin);
			fclose(stdout);
			return 0;	
		}
		ans += qpow(2,q);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}