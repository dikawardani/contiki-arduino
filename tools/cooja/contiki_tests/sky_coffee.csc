<?xml version="1.0" encoding="UTF-8"?>
<simconf>
  <project>../apps/mrm</project>
  <project>../apps/mspsim</project>
  <project>../apps/native_gateway</project>
  <simulation>
    <title>test</title>
    <delaytime>0</delaytime>
    <ticktime>1</ticktime>
    <randomseed>123456</randomseed>
    <motedelay>0</motedelay>
    <radiomedium>
      se.sics.cooja.radiomediums.UDGM
      <transmitting_range>50.0</transmitting_range>
      <interference_range>100.0</interference_range>
      <success_ratio_tx>1.0</success_ratio_tx>
      <success_ratio_rx>1.0</success_ratio_rx>
    </radiomedium>
    <motetype>
      se.sics.cooja.mspmote.SkyMoteType
      <identifier>sky1</identifier>
      <description>Sky Mote Type #1</description>
      <source>../../../examples/sky/test-coffee.c</source>
      <commands>make test-coffee.sky TARGET=sky</commands>
      <firmware>../../../examples/sky/test-coffee.sky</firmware>
      <moteinterface>se.sics.cooja.interfaces.Position</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspIPAddress</moteinterface>
      <moteinterface>se.sics.cooja.interfaces.Mote2MoteRelations</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspClock</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.MspMoteID</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyButton</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyFlash</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyByteRadio</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkySerial</moteinterface>
      <moteinterface>se.sics.cooja.mspmote.interfaces.SkyLED</moteinterface>
    </motetype>
    <mote>
      se.sics.cooja.mspmote.SkyMote
      <motetype_identifier>sky1</motetype_identifier>
      <interface_config>
        se.sics.cooja.interfaces.Position
        <x>97.11078411573273</x>
        <y>56.790978919276014</y>
        <z>0.0</z>
      </interface_config>
      <interface_config>
        se.sics.cooja.mspmote.interfaces.MspMoteID
        <id>1</id>
      </interface_config>
    </mote>
  </simulation>
  <plugin>
    se.sics.cooja.plugins.SimControl
    <width>248</width>
    <z>2</z>
    <height>200</height>
    <location_x>0</location_x>
    <location_y>0</location_y>
    <minimized>false</minimized>
  </plugin>
  <plugin>
    se.sics.cooja.plugins.VisState
    <width>300</width>
    <z>1</z>
    <height>300</height>
    <location_x>1239</location_x>
    <location_y>0</location_y>
    <minimized>false</minimized>
  </plugin>
  <plugin>
    se.sics.cooja.plugins.LogListener
    <plugin_config>
      <filter />
      <history>256</history>
    </plugin_config>
    <width>1539</width>
    <z>0</z>
    <height>209</height>
    <location_x>0</location_x>
    <location_y>945</location_y>
    <minimized>false</minimized>
  </plugin>
</simconf>
