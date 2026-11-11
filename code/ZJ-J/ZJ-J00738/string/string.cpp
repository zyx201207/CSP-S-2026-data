#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node
{
	char c;
	long long cnt;
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n,Max=0;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].cnt>>a[i].c;
	//	cout<<a[i].c<<" "<<a[i].cnt;
		if(Max<a[i].cnt) Max=a[i].cnt;
	}
	if(n==1)
		cout<<0<<"\n";
	else if(Max<=500)
	{
		string str="";
		long long length=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].cnt;j++)
			{
				str+=a[i].c;
			}
		}
		length=str.size();
		long long middle=length/2-1;
		long long change=0;
		for(int i=0,j=length-1;i<=middle;i++,j--)
		{
			if(i==j) break;
		//	cout<<str[i]<<" "<<str[j]<<"\n";
			if(str[i]!=str[j]) change++;
		}
		cout<<change<<"\n";
	}
	else
	{
		long long sum[n];
		long long length=0;
		sum[0]=0;
		for(int i=1;i<=n;i++)
			length+=a[i].cnt,sum[i]=length;
	//	cout<<length<<"\n";
		long long middle=length/2+(length%2);
		bool not_split=false;
		long long l=0,r=n,ans;
		while(l<=r)
		{
			long long mid=l+r>>1;
		//	cout<<l<<" "<<r<<"\n";
			//cout<<mid<<" "<<sum[mid]<<"\n";
			if(sum[mid]==middle) 
			{
				not_split=true;
			//	cout<<l<<" "<<r<<" "<<sum[mid]<<" "<<middle<<"\n"; 
				ans=mid;
				break;
			}
			if(sum[mid]>middle) r=mid-1,ans=mid;
			else l=mid+1;
		}
		vector<node>left;
		vector<node>right;
		if(not_split) 
		{
		//	cout<<"no split\n";
			for(int i=1;i<=ans;i++) left.push_back({a[i].c,a[i].cnt});
			
			for(int i=n;i>=ans+1;i--) right.push_back({a[i].c,a[i].cnt});
		}
		else
		{
			for(int i=1;i<ans;i++) left.push_back({a[i].c,a[i].cnt});
			
			for(int i=n;i>=ans+1;i--) right.push_back({a[i].c,a[i].cnt});
			
			long long split=sum[ans];
			char c=a[ans].c;
		//	cout<<middle-sum[ans-1]<<" "<<sum[ans]-middle<<"\n";
			left.push_back({c,middle-sum[ans-1]});
			right.push_back({c,sum[ans]-middle});
		}
		long long sizea=0,sizeb=0; 
		char ln,rn;
		long long ls=0,rs=0;
		long long different=0;
		for(int i=0,j=0;i<left.size(),j<right.size();)
		{
			if(ls==rs)
			{
			//	cout<<"-----------\n     1     ------------\n";
				//cout<<"Before : "<<ls<<" "<<rs<<" "<<ln<<" "<<rn<<"\n";
				ls=left[i].cnt;
				ln=left[i].c;
				rs=right[j].cnt;
				rn=right[j].c;
				different+=min(ls,rs)*(ln!=rn);
			//	cout<<"now : "<<ls<<" "<<rs<<" "<<ln<<" "<<rn<<"\n";
				int ddd=min(rs,ls);
				rs-=ddd;
				ls-=ddd;
				i++,j++;
			}
			else if(ls>rs)
			{
			//	cout<<"-----------\n     2     ------------\n";
			//	cout<<"Before : "<<ls<<" "<<rs<<" "<<ln<<" "<<rn<<"\n";
				rs+=right[j].cnt;
				rn=right[j].c;
				different+=min(ls,rs)*(ln!=rn);
			//	cout<<"now : "<<ls<<" "<<rs<<" "<<ln<<" "<<rn<<"\n";
				int ddd=min(rs,ls);
				rs-=ddd;
				ls-=ddd;
				j++;
			}
			else if(ls<rs)
			{
			//	cout<<"-----------\n     3     ------------\n";
				ls+=left[i].cnt;
				ln=left[i].c;
				different+=min(ls,rs)*(ln!=rn);
			//	cout<<ls<<" "<<rs<<" "<<ln<<" "<<rn<<"\n";
				int ddd=min(rs,ls);
				rs-=ddd;
				ls-=ddd;
				i++;
			}
		//	cout<<i<<" "<<j<<"\n";
		//	cout<<ls<<" "<<rs<<" "<<ln<<" "<<rn<<"\n";
		}
		cout<<different<<"\n";
	}
	return 0;
}

