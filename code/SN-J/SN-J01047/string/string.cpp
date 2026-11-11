#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct wd{
	long long num;
	char c;
}a[200005];
vector<wd> p1,p2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//step1
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	sum/=2;
	int i=1;
	while(sum>=0){
		if(sum>=a[i].num){
			sum-=a[i].num;
			wd x={a[i].num,a[i].c};
			p1.push_back(x);
		}
		else{
			if(sum!=0){
			wd x={sum,a[i].c};
			p1.push_back(x);}
			wd xx={a[i].num-sum,a[i].c};
			p2.push_back(xx);
			i++;
			break;
		}
		i++;
	}
	while(i<=n){
		wd x={a[i].num,a[i].c};
		p2.push_back(x);
		i++;
	}
	/*
	for(int i=0;i<p1.size();i++)
	cout<<p1[i].num<<" "<<p1[i].c<<endl;
	cout<<endl;
	for(int i=0;i<p2.size();i++)
	cout<<p2[i].num<<" "<<p2[i].c<<endl;*/
	
	//step2
	
	long long l=0,r=p2.size()-1;
	//cout<<l<<" "<<p1[l].num<<" "<<r<<" "<<p2[r].num<<endl;
	bool b; 
	while(l<p1.size()&&r>=0){
		if(p1[l].num>p2[r].num){
			b=1; 
		}
		else if(p1[l].num!=p2[r].num){
			b=0;
		}
		else{
			if(p1[l].c!=p2[r].c)ans+=p1[l].num;
			l++;
			r--;
			continue;
		}
		if(p1[l].c==p2[r].c){
			if(b){
				p1[l].num-=p2[r].num;
				r--;	
			}
			else{
				p2[r].num-=p1[l].num;
				l++;
			}
		}
		else{
			if(b){
				ans+=p2[r].num;
				p1[l].num-=p2[r].num;
				//cout<<p1[l].num;
				r--;
			}
			else{
				ans+=p1[l].num;
				p2[r].num-=p1[l].num;
				l++;
			}
		}
		//cout<<l<<" "<<p1[l].num<<" "<<r<<" "<<p2[r].num<<endl;
	}
	cout<<ans;
}
