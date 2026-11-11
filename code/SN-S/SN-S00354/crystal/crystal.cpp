#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","t",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	vector<int> a(n);
	int cnt=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	while(n/2!=0){
		int mid=n/2;
		int l=mid-1;
		int r=mid+1;
		if(a[mid]-a[l]>a[r]-a[mid]){
			if(a[r]==a[mid]){
				m-=a[mid]-a[l];
				cnt+=1;
				if(m<0){
				    cout<<cnt;
				    return 0;
			    }
			    cnt++;
			}else{
				m-=a[r]-a[mid];
			    if(m<0){
				    cout<<cnt;
				    return 0;
			    }
			    cnt++;
			}
		}else if(a[mid]-a[l]<a[r]-a[mid]){
			if(a[l]==a[mid]){
				m-=a[r]-a[mid];
				cnt+=1;
				if(m<0){   
				    cout<<cnt;
				    return 0;
			    }
			    cnt++;
			}else{
				m-=a[mid]-a[l];
			    if(m<0){
				    cout<<cnt;
				    return 0;
			    }
			    cnt++;
			}
		}else{
			m-=a[mid]-a[l];
			if(m<0){
				cout<<cnt;
				return 0;
			}
			cnt++;
			m-=a[r]-a[mid];
			if(m<0){
				cout<<cnt;
				return 0;
			}
			cnt++;
		}
		l--;
		r++;
	}
	return 0;
}
