数据结构的基本概念和术语
1.	数据：对客观事物的符号表示，在计算机科学中是指所有能输入到计算机中并被计算机程序处理的符号总称
2.	数据元素：是数据的基本单位，在计算机程序中通常做为一个整体进行考虑和处理。有时一个数据元素可由若干个数据项组成
3.	数据对象：性质相同的数据元素的集合，是数据的一个子集
4.	数据结构：是相互之间存在一种或多种特定关系的数据元素的集合
4.1	集合：结构中的数据元素之间除了同属于一个集合的关系外，别无其他关系
4.2	线性结构：结构中的数据元素之间存在一个对一个的关系
4.3	树形结构：结构中的数据元素之间存在一个对多个的关系
4.4	图状结构或网状结构：结构中的数据元素之间存在多个对多个的关系
5.	逻辑结构：结构定义中的“关系”描述的是数据元素之间的逻辑关系
6.	物理结构（储存结构）：数据结构在计算机中的表示（又称映像），它包括元素的表示和关系的表示
7.	位(bit)：计算机中表示信息的最小单位是二进制数的一位
8.	元素(结点)：用一个由若干位组合起来形成的的一个位串表示一个数据元素
9.	数据域：数据元素由若干数据项组成时，位串中对应于各个数据项的子位串
10.	数据元素之间的关系在计算机中由两种不同的表示方法：顺序映像和非顺序映像，并且由此得到了两种不同的存储结构：顺序存储结构和链式存储结构
11.	顺序映像的特点是借助元素在存储器中的相对位置来表示数据元素之间的逻辑关系 
12.	非顺序映像的特点是借助指示元素存储地址的指针表示数据元素之间的逻辑关系
13.	数据类型和数据结构密切相关的，因此数据类型是一个值的类型和定义在这个值集上的一组操作的总称
14.	抽象数据类型：一个数学模型以及定义在该模型之上的一组操作
15.	原子类型：原子类型的变量的值是不可分解的
16.	固定聚合类型：该类型的变量其值由确定数目的成分按某种结构组成
17.	可变聚合类型：和固定聚合类型相比较，构成可变聚合类型值得成分的数目不确定
18.	多形数据类型：是指其值的成分不确定的数据类型
19.	算法：
19.1	有穷性：一个算法必须总是在执行有穷不之后结束，且每一步都可在又穷时间内完成
19.2	确定性：算法中的每一条指令必须有确定的含义
19.3	可行性：算法中描述的操作都是可通过以及实现的基本运算执行有限次来实现的
19.4	输入
19.5	输出
20.	算法设计的要求：
20.1	正确性，可读性，健壮性，效率和低存储量的需求
21.	算法效率的度量：
21.1	时间复杂度：算法中基本操作重复执行的次数是问题规模n的某个函数f(n)，算法的时间量度记作T(n)=O(f(n))随问题规模n的扩大，算法执行时间的增长率和f(n)的增长率相同，称做算法的渐进时间复杂度
22.	频度：该语句重复执行的次数
23.	算法的存储空间需求：
空间复杂度S(n)=O(f(n))做为算法所需存储空间的量度
