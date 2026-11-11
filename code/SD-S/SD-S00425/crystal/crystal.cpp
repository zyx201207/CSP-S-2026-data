#include <bits/stdc++.h>
using namespace std;
int hc,n_hc,m_xb,m_hc;//缓存，缓存出现次数，最大数最后一次下标，最大次数 
long long a[500005],m;
int n,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	hc=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]==hc) n_hc++;
		else if(a[i]!=hc) hc=1;
		if(n_hc>m_hc){
			m_hc=n_hc;
			m_xb=i;
		}
	}
	if(m_xb-m_hc+1>1){
		int xb=m_xb-m_hc+1;
		sum+=m_hc;
	for(int i=xb-1;i>=1;i--){
		if(m>a[i+1]-a[i]){
		m-=a[xb]-a[i];
		sum++;
		} else break;
	}
	cout << sum;
	return 0;
	}
	
	int mid=(n+1)/2;
	for(int i=1;i<=n;i++)
	{
		if(a[mid]==a[i]) sum++;
	 } 
	for(int i=mid-1;i>=1;i--){
		if(m>a[i+1]-a[i]){
		m-=a[mid]-a[i];
		sum++;
		} else break;
	}
	cout << sum;
	return 0;
} 
