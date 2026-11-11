#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c=1048575,ma=-1;
	vector<int> a_;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		c&=a;
		ma=max(ma,a); 
		a_.push_back(a);
	}
	if(m==n){
		cout<<c;
	}
	else if(m==1){
		cout<<ma;
	}
	else if(m==2){
		ma=-1;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				ma=max(ma,a_[i]&a_[j]);
			}
		}
		cout<<ma;
	}
	else if(m==3){
		ma=-1;
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					ma=max(ma,a_[i]&a_[j]&a_[k]);
				}
			}
		}
		cout<<ma;
	}
	else if(m==3){
		ma=-1;
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					ma=max(ma,a_[i]&a_[j]&a_[k]);
				}
			}
		}
		cout<<ma;
	}
	else if(m==4){
		ma=-1;
		for(int i=0;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int l=k+1;l<n;l++){
						ma=max(ma,a_[i]&a_[j]&a_[k]&a_[l]);
					}
				}
			}
		}
		cout<<ma;
	}
	else if(m==5){
		ma=-1;
		for(int i=0;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int l=k+1;l<n-1;l++){
						for(int o=l+1;o<n;o++){
							ma=max(ma,a_[i]&a_[j]&a_[k]&a_[l]&a_[o]);
						}
					}
				}
			}
		}
		cout<<ma;
	}
	else if(m==(n-1)){
		ma=-1;
		for(int i=0;i<n;i++){
			int c_=1048575;
			for(int p=0;p<n;p++){
				if(p!=i){
					c&=a_[p];
				}
			}
			ma=max(ma,c);
		}
		cout<<ma;
	}
	else if(m==(n-2)){
		ma=-1;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int c_=1048575;
				for(int p=0;p<n;p++){
					if(p!=i&&p!=j){
						c&=a_[p];
					}
				}
				ma=max(ma,c);
			}
		}
		cout<<ma;
	}
	else if(m==(n-3)){
		ma=-1;
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					int c_=1048575;
					for(int p=0;p<n;p++){
						if(p!=i&&p!=j&&p!=k){
							c&=a_[p];
						}
					}
					ma=max(ma,c);
				}
			}
		}
		cout<<ma;
	}
	else if(m==(n-4)){
		ma=-1;
		for(int i=0;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int l=k+1;l<n;l++){
						int c_=1048575;
						for(int p=0;p<n;p++){
							if(p!=i&&p!=j&&p!=k&&p!=l){
								c&=a_[p];
							}
						}
						ma=max(ma,c);
					}
				}
			}
		}
		cout<<ma;
	}
	else if(m==(n-5)){
		ma=-1;
		for(int i=0;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int l=k+1;l<n-1;l++){
						for(int o=l+1;o<n;o++){
							int c_=1048575;
							for(int p=0;p<n;p++){
								if(p!=i&&p!=j&&p!=k&&p!=l){
									c&=a_[p];
								}
							}
							ma=max(ma,c);
						}
					}
				}
			}
		}
		cout<<ma;
	}
	else{
		sort(a_.begin(),a_.begin()+a_.size(),greater<int>());
		cout<<a_[n-m-1];
	}
	return 0;
}
