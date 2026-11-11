#include<bits/stdc++.h>
using namespace std;
const int N_=5e5+10;
int n_;
long long m_;
long long a_[N_];
long long pre_[N_];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n_>>m_;
    bool l_=0;
    for(int i=1;i<=n_;i++){
    	cin>>a_[i];
    	
	}
	sort(a_+1,a_+n_+1);
	int cha_=a_[2]-a_[1];
	for(int i=1;i<=n_;i++){
		
		if(i>=2 and a_[i]-a_[i-1]!=cha_) l_=1;
	}
	if(l_==1){
	    long long max_cnt=0;
	    for(int i=1;i<=n_;i++){
		    long long sum_=0;
		    long long cnt_=0;
		    for(int j=i;j>=1;j--){
			    sum_+=a_[i]-a_[j];
			    if(sum_<=m_) cnt_++;
			    else break;
		    }
		    max_cnt=max(max_cnt,cnt_);
	    }
	    cout<<max_cnt;
	}
	else if(l_==0){
	    long long sum_=0;
	    long long cnt_=0;
		for(int i=n_;i>=1;i--){
			sum_+=a_[n_]-a_[i];
			if(sum_<=m_) cnt_++;
			else break;
		}
		cout<<cnt_;
	}
	
	return 0;
} 
