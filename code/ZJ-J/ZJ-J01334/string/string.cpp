#include<bits/stdc++.h>
using namespace std;
long long n,m,c,o,t,ans;
string s;
pair<char,long long> a[200010];
pair<char,long long> sum1,sum2,sum3;
void ans1(long long i,long long j){
	if(a[i].second==a[j].second){
		if(a[i].first!=a[j].first){
			ans+=a[i].second;
		}
	}
	else if(a[i].second>a[j].second){
		if(a[i].first!=a[j].first){
			ans+=a[j].second;
		}
		sum1={a[i].first,a[i].second-a[j].second};
	}
	else{
		if(a[i].first!=a[j].first){
			ans+=a[i].second;
		}
		sum2={a[j].first,a[j].second-a[i].second};
	}
}
void ans2(long long i,long long j){
	if(a[j].first!=sum1.first){
		ans+=sum1.second;
	}
	a[j].second-=sum1.second;
	sum1=sum3;
	ans1(i,j);
}
void ans3(long long i,long long j){
	if(a[i].first!=a[j].first){
		ans+=sum2.second;
	}
	a[i].second-=sum2.second;
	sum2=sum3;
	ans1(i,j);
}
void ans4(long long i,long long j){
	if(a[j].second>sum1.second){
		ans2(i,j);
	}
	else if(a[j].second<sum1.second){
		while(a[j].second<sum1.second){
			if(a[j].first!=sum1.first){
				ans+=a[j].second;
			}
			sum1.second-=a[j].second;
			j--;
		}
		ans2(i,j);
	}
	else if(a[j].second==sum1.second){
		if(a[j].first!=sum1.first){
			ans+=a[j].second;
		}
		j--;
		ans1(i,j);
	}
}
void ans5(long long i,long long j){
	if(a[i].second>sum2.second){
		ans3(i,j);
	}
	else if(a[i].second<sum2.second){
		while(a[i].second<sum2.second){
			if(a[i].first!=sum2.first){
				ans+=a[i].second;
			}
			sum2.second-=a[i].second;
			i++;
		}
		ans3(i,j);
	}
	else if(a[i].second==sum2.second){
		if(a[i].first!=sum2.first){
			ans+=a[i].second;
		}
		i++;
		ans1(i,j);
	}
}
void ans6(){
	for(long long i=1,j=n;i<=c,j>=c;i++,j--){
		if(sum1.second==sum2.second){
			if(sum1.first!=sum2.first){
				ans+=sum1.second;
			}
			sum1=sum3;
			sum2=sum3;
			ans1(i,j);
		}
		else if(sum1.second!=0&&sum2.second==0){
			ans4(i,j);
		}
		else if(sum1.second==0&&sum2.second!=0){
			ans5(i,j);
		}
		else{
			if(sum1.second>sum2.second){
				if(sum1.first!=sum2.first){
					ans+=sum2.second;
				}
				sum1.second-=sum2.second;
				sum2=sum3;
				ans4(i,j);
			}
			else{
				if(sum1.first!=sum2.first){
					ans+=sum1.second;
				}
				sum2.second-=sum1.second;
				sum1=sum3;
				ans5(i,j);
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].second>>a[i].first;
		m+=a[i].second;
		o=max(o,a[i].second);
	}
	for(int i=1;i<=n;i++){
		t+=a[i].second;
		if(t>m/2){
			c=i;
			break;
		}
	}
	ans6();
	if(sum1.second!=sum2.second){
		if(sum1.second>sum2.second){
			if(sum1.first!=sum2.first){
				ans+=sum2.second;
			}
			sum2=sum3;
			sum2={a[c].first,a[c].second};
		}
		else if(sum1.second<sum2.second){
			if(sum1.first!=sum2.first){
				ans+=sum1.second;
			}
			sum1=sum3;
			sum1={a[c].first,a[c].second};
		}
		else{
			if(sum1.first!=sum2.first){
				ans+=sum1.second;
			}
			cout<<ans;
			return 0;
		}
		if(sum1.second>sum2.second){
			if(sum1.first!=sum2.first){
				ans+=sum2.second;
			}
			cout<<ans;
			return 0;
		}
		else if(sum1.second<=sum2.second){
			if(sum1.first!=sum2.first){
				ans+=sum1.first;
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}