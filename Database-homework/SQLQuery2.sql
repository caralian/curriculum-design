
create login U1 with password ='123',default_database=waterFeemanage
create login U2 with password ='123',default_database=waterFeemanage
create login U3 with password ='123',default_database=waterFeemanage
create login U4 with password ='123',default_database=waterFeemanage
create login U5 with password ='123',default_database=waterFeemanage
create login U6 with password ='123',default_database=waterFeemanage
create login U7 with password ='123',default_database=waterFeemanage
create login U8 with password ='123',default_database=waterFeemanage
create login U9 with password ='123',default_database=waterFeemanage
create login U10 with password ='123',default_database=waterFeemanage


create user U1 for login U1 
create user U2 for login U2 with default_schema=dbo/*默认架构dbo*/
create user U3 for login U3 /*不写默认架构也是dbo*/
create user U4 for login U4  
create user U5 for login U5 
create user U6 for login U6 
create user U7 for login U7 
create user U8 for login U8
create user U9 for login U9 
create user U10 for login U10 

create login S1 with password ='123',default_database=waterFeemanage
create login S2 with password ='123',default_database=waterFeemanage
create login S3 with password ='123',default_database=waterFeemanage

create user S1 for login S1
create user S2 for login S2 
create user S3 for login S3 

exec sp_helpuser /*查看用户信息*/

grant select
on  客户信息
to public

grant select,update,delete,insert
on  客户信息
to S1,S2,S3

grant/revoke/deny “权限”
on “表名或视图名”
to “n个客户和n业务员”  注：双引号内不为空

grant/revoke/deny “权限”
on “表名或视图名”
to “n个客户和n业务员”  注：双引号内不为空