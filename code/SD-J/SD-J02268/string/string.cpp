#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long maxn;
vector<long long>pos;
long long find_pos(long long n)
{
	long long l=1,r=maxn;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(pos[mid]==n)return mid;
		else if(pos[mid]>n)r=mid-1;
		else l=mid+1;
	}
	return l-1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;cin>>n;
	vector<long long>s(n+10);
	pos.resize(n+10);
	vector<char>ch(n+10);
	long long cnt_cur=0;
	long long sum=0;
	char ch_cur=' ';
	pos[1]=1;
	for(int i=1;i<=n;i++)
	{
		long long k;
		char opt;
		cin>>k>>opt;
		if(opt!=ch_cur){
			if(cnt_cur!=0){
				maxn++;
				s[maxn]=cnt_cur;
				ch[maxn]=ch_cur;
				pos[maxn+1]=sum+1;
			}
			cnt_cur=k;
			ch_cur=opt;
		}else{
			cnt_cur+=k;
		}
		sum+=k;
	}
	maxn++;
	s[maxn]=cnt_cur;
	ch[maxn]=ch_cur;
	pos[maxn+1]=sum+1;
	long long l=1,r=sum;
	long long cnt=0;
	while(l<=r)
	{
		long long posl=find_pos(l);
		long long posr=find_pos(r);
		long long resl=pos[posl+1]-l;
		long long resr=r-pos[posr]+1;
		if(resl<resr){
			l+=resl,r-=resl;
		}else{
			l+=resr,r-=resr;
		}
		if(ch[posl]!=ch[posr])cnt+=min(resl,resr);
	}
	cout<<cnt<<"\n";
	return 0;
}
