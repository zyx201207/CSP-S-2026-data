#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5500;
const int M = 1e6+10;
struct l
{
    int num,cnt;
}b[N];
bool f=0;
int n,m,a[N],cnt=1,k,num = -1,o;
int c[M],cc[M];
bool cmp(l a,l b)
{
    return a.cnt > b.cnt;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == a[i-1])
        {
        	b[cnt].num = a[i];
        	b[cnt].cnt++;
            
        }
        else
        {
        	cnt++;
	        b[cnt].num = a[i];
	        b[cnt].cnt++;
    	}
    }
    sort(b+1,b+cnt+1,cmp);
    for(int i = 1;i <= cnt;i++)
    {
    	if(b[i].num >= 0)
        	c[b[i].num] = b[i].cnt;
        else
        	cc[abs(b[i].num)] = b[i].cnt;
    }
    for(int i = 1;i <= cnt;i++)
    {
        int g=1,p=b[i].cnt,k = 0,x,o = 0;
        int j=b[i].num;
        while(k <= m && (b[i].num-g) >= a[1])
        {
            if((j-g)>=0)
            {
            	k += c[j-g]*g;
            	o += c[j-g];
            }
            else
            {
            	k += cc[abs(j-g)]*g;
            	o += c[abs(j-g)];
            }
            if(k <= m)
            {
            	if((j-g)>=0)
                	p += c[j-g];
                else
            		p += cc[abs(j-g)];
            }
            else if(o <= m)
            {
            	if((j-g)>=0)
            		p += m / g;
            	else
            		p += cc[abs(m/g)];
			}
            else 
                break;
            g++;
        }
        num = max(num,p);
    }
    cout << num << endl;

    return 0;
}
