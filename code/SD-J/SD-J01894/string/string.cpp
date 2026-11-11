#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

struct Str{
	int cnt;
	char ch;
};

const int N=2e5+5;
int n;
vector<Str> str;
int L;

namespace debug{
	void print(const vector<Str>&a){
		for(auto i:a){
			cout<<i.cnt<<i.ch;
		}
		cout<<endl;
	}
}

int cut(int pos){
	int begin=1;
	int end=1;
	for(int i=1;i<=n;i++){
		end=begin+str[i].cnt-1;
		
		if(begin<=pos&&pos<end){
			int first_cnt=0,second_cnt=0;
			first_cnt=pos-begin+1;
			second_cnt=str[i].cnt-first_cnt;
			
			str[i].cnt=first_cnt;
			str.insert(str.begin()+i+1,{second_cnt,str[i].ch}); 
			++n;
			return i;
		}if(pos==end)return i;
		
		begin+=str[i].cnt;
	}
	return -1;
}
int cut(vector<Str>&a,int pos){
	int begin=0;
	int end=1;
	for(int i=0;i<a.size();i++){
		end=begin+a[i].cnt-1;
		
		if(begin<=pos&&pos<end){
			int first_cnt=0,second_cnt=0;
			first_cnt=pos-begin+1;
			second_cnt=a[i].cnt-first_cnt;
			
			a[i].cnt=first_cnt;
			a.insert(a.begin()+i+1,{second_cnt,a[i].ch}); 
			return i;
		}if(pos==end)return i;
		
		begin+=a[i].cnt;
	}
	return -1;
}

void cutinto(vector<Str>&a,vector<Str>&b){
	vector<int>cutpos;
	{
		int begin=0;
		for(int i=0;i<a.size();i++){
			begin+=a[i].cnt;
			cutpos.push_back(begin-1);
		}
	}
	{
		int begin=0;
		for(int i=0;i<b.size();i++){
			begin+=b[i].cnt;
			cutpos.push_back(begin-1);
		}
	}
	for(auto i:cutpos){
//	cout<<i<<' ';
	cut(a,i),cut(b,i);
	}
//	cout<<endl;
}

int compare(vector<Str>&a,vector<Str>&b){
	int ans=0;
	cutinto(a,b);
//	debug::print(a);
//	debug::print(b);
	for(int i=0;i<a.size();i++){
		if(a[i].ch!=b[i].ch)ans+=a[i].cnt;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	str.resize(n+5);
	for(int i=1;i<=n;i++){
		int cnt;
		char ch;
		cin>>cnt>>ch;
		str[i]={cnt,ch};
		L+=cnt;	
	}
	int mid=(L+1)/2;
//	debug::print(str);
	if(L%2==0){	
		int mid_cut=cut(mid);
		vector<Str>tmp1(str.begin()+1,str.begin()+mid_cut+1);
		vector<Str>tmp2(str.begin()+mid_cut+1,str.begin()+n+1);
		reverse(tmp1.begin(),tmp1.end());
		cout<<compare(tmp1,tmp2)<<endl;
	}
	else{
		int mid_cut=cut(mid);
		mid_cut=cut(mid-1);
		vector<Str>tmp1(str.begin()+1,str.begin()+mid_cut+1);
		vector<Str>tmp2(str.begin()+mid_cut+2,str.begin()+n+1);
		reverse(tmp1.begin(),tmp1.end());
//		debug::print(tmp1);
//		debug::print(tmp2);
		cout<<compare(tmp1,tmp2)<<endl;
	}
}
