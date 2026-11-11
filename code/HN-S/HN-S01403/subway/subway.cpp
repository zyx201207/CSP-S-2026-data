using namespace std;
int a[500005];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,s,e,k;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>a[i];
    }for(int i = 1;i<=n;i++){
        cin>>k;
        for(int i = 1;i<=2*k;i++){
            cin>>d;
        }int sum = 0;
    }for(int i = 1;i<=q;i++){
        cin>>s>>e;
        cout<<(a[s]+a[e]);
    }






    return 0;
}
